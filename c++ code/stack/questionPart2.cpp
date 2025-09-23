#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Q1stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;
    Q1stack(int size)
    {
        arr = new int[size];
        this->top1 = -1;
        this->top2 = size;
        this->size = size;
    }
    void push1(int data)
    {
        if ((top2 - top1) == 1)
        {
            cout << "overflow" << endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data)
    {
        if ((top2 - top1) == 1)
        {
            cout << "overflow" << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "underflow" << endl;
        }
        else
        {
            top1--;
        }
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "underflow" << endl;
        }
        else
        {
            top2++;
        }
    }
    void print()
    {
        cout << "top1 : " << top1 << endl;
        cout << "top2 : " << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Q1stack()
    {
        delete[] arr;
    }
};
bool checkRedundant(string str)
{
    stack<char> st;
    for (char ch : str)
    {
        if (ch == '(' || ch == '+' || ch == '*' || ch == '-' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '*' || temp == '-' || temp == '/')
                {
                    operatorCount++;
                }
                st.pop();
            }
            // yha pr tbhi aaoge agr stack empty ya stack  k top pr opening bracket hoga
            st.pop();
            if (operatorCount == 0)
            {
                return true;
            }
        }
    }
    // agr yha tk aaye hai mtlb redundant ni mila
    return false;
}
int main()
{
    // 1. implement 2 stack using one array
    // Q1stack st1(9);
    // st1.push1(100);
    // st1.push1(100);
    // st1.push1(100);
    // st1.push1(100);
    // st1.push1(100);
    // st1.push2(200);
    // st1.push2(200);
    // st1.push2(200);
    // st1.push2(200);
    // st1.print();
    // st1.push1(500);
    // st1.push2(500);
    // st1.pop1();
    // st1.pop2();

    stack<int> st;
    st.push(710);
    st.push(0);
    st.push(80);
    st.push(50);

    // 2. VALID PARANTHESIS - LC: 20

    // 3. CHECK REDUNDANT BRACKET
    string str = "(a+b)*(c+d)";
    bool ans = checkRedundant(str);
    if (ans)
    {
        cout << "redundant brackets present" << endl;
    }
    else
    {
        cout << "no redundant brackets" << endl;
    }

    // 4. implement a min stack - LC: 155
}