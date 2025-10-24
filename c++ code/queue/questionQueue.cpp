#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
void reverseQueue(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
void reverseByRecursion(queue<int> &q)
{
    // base case
    if (q.empty())
    {
        return;
    }

    // hm ek case solve krenge
    int temp = q.front();
    q.pop();
    reverseByRecursion(q);
    q.push(temp);
}
void reverseK(queue<int> &q, int k)
{
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    int n = q.size();
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}
void interleaveQueue(queue<int> &q)
{
    int size = q.size();
    if (size == 0)
    {
        return;
    }
    int mid = size / 2;
    // odd wala case ni hota hai isme
    queue<int> firstHalf;
    for (int i = 1; i <= mid; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }
    // after this the q queue will only have the seond half element therefore it will our second half queue

    // merging both half
    for (int i = 1; i <= mid; i++)
    {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}
vector<int> firstNegIntInKWindows(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    deque<int> dq;
    // process first window
    for (int i = 0; i < k; i++)
    {
        int e = arr[i];
        if (e < 0)
        {
            dq.push_back(i);
        }
    }
    // process remaining windows -> removal and addition
    for (int i = k; i < n; i++)
    {
        // aage badhne se phle purani wali window ka answer nikal lo
        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[dq.front()]);
        }
        // then dequeue mei se is index ko remove kr do agr ye next window k index mei na aaa rha ho toh
        // REMOVAL
        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }
        // ADDITION
        // agr negative next element mile toh uska index add kr do
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // upr wale process se hm last wali window ka answer print ni kr paynge therefore usko alg se handle kr rhe hai
    if (dq.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(arr[dq.front()]);
    }
    return ans;
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // q.push(60);

    // // question 1 : revrsing a queue
    // // solution by using stack
    // printQueue(q);
    // reverseQueue(q);
    // printQueue(q);
    // // solutio by recursion
    // reverseByRecursion(q);
    // printQueue(q);

    // // question 2 : rverse first k elements of queue
    // // solution using stack push k i stakc and then in queue and remaining pop and push
    // int k =4;
    // reverseK(q,k);
    // printQueue(q);

    // // questoin 3: interleave first and second half of the queue;
    // //  solution by breaking the queue in two new queue and then merge , stack will reverse the order therefore we do not use it
    // printQueue(q);
    // interleaveQueue(q);
    // printQueue(q);

    /// question 4: find neagtive interger in every window of size k
    vector<int> arr = {2, -5, 4, -1, -2, 0, 5};
    int k = 2;
    vector<int> ans=firstNegIntInKWindows(arr, k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}