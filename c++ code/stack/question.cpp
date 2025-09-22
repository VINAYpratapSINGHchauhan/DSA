#include <iostream>
#include <string>
#include <stack>
using namespace std;
int solve(stack<int> st, int pos)
{
    if (pos == 1)
    {
        return st.top();
    }
    int temp = st.top();
    st.pop();
    int recAns = solve(st, pos - 1);
    st.push(temp);
    return recAns;
}
int findMidElement(stack<int> st)
{
    int size = st.size();
    if (st.empty())
    {
        return -1;
    }
    int midPos;
    if (!(size & 1))
    { // even
        midPos = size / 2;
    }
    else
    { // odd
        midPos = (size / 2) + 1;
    }
    int ans = solve(st, midPos);
    return ans;
}

void insertAtBottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        // cout << "element inserted successfully " << endl;
        return;
    }
    else
    {
        int temp = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(temp);
    }
}
void reverseStack(stack<int>&st){
    if(st.empty()){
        // cout<<"stack revresed successfully "<<endl;
        return;
    }
    int temp=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,temp);
}
void insertInSorted(stack<int>&st,int e){
    if(st.empty()||e>st.top()){
        st.push(e);
        return;
    }
    int temp=st.top();
    st.pop();
    insertInSorted(st,e);
    st.push(temp);
}
void sortTheStack(stack<int> & st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    sortTheStack(st);
    insertInSorted(st,temp);
}
int main()
{
    stack<int> st;
    st.push(70);
    st.push(60);
    st.push(50);
    st.push(40);
    st.push(30);
    st.push(20);
    st.push(10);

    // 1. find middle of the stack
    // cout << "middle element is: " << findMidElement(st) << endl;

    // 2. insert at the bottom of the stack
    // int elementToInsertAtLast = 590;
    // insertAtBottom(st, elementToInsertAtLast);
    // while ((!st.empty()))
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    // 3. REVERSE THE STACK
    // cout << "before reversal : " << endl;
    // while ((!st.empty()))
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;
    // reverseStack(st); //reverse the stack
    // cout << "after reversal : " << endl;
    // while ((!st.empty()))
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    // 4. INSERT ELEMENT AT ITS APPROPRIATE PLACE IN SORTED STACK
    //creating sorted stack
    stack <int> sortedST;
    sortedST.push(10);
    sortedST.push(20);
    sortedST.push(30);
    sortedST.push(40);
    // insertInSorted(sortedST,110);
    // while ((!sortedST.empty()))
    // {
    //     cout << sortedST.top() << " ";
    //     sortedST.pop();
    // }
    // cout << endl;

    // 5. SORT THE UNSORTED STACK
    stack<int> unsorted;
    unsorted.push(52);
    unsorted.push(101);
    unsorted.push(2);
    unsorted.push(9);
    unsorted.push(11);
    sortTheStack(unsorted);
     while ((!unsorted.empty()))
    {
        cout << unsorted.top() << " ";
        unsorted.pop();
    }
    cout << endl;

}