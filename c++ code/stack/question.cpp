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
int main()
{
    // 1. find middle of the stack
    stack<int> st;
    // st.push(70);
    // st.push(60);
    // st.push(50);
    // st.push(40);
    // st.push(30);
    // st.push(20);
    // st.push(10);

    cout << "middle element is: " << findMidElement(st) << endl;
}