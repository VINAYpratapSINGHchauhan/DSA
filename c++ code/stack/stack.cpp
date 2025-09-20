#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    // stack starting from there
    
    //creation
    stack<int> st1;
    //insertion
    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);
    //size check
    cout<<"stack size : "<<st1.size()<<endl;
    //remove
    st1.pop();
    cout<<"stack size : "<<st1.size()<<endl;
    cout<<"stack is empty : "<<st1.empty()<<endl;
    //top element
    cout<<st1.top()<<endl;

    //stack implementation
    //DONE IN NOTEBOOK
    
    // example on stack 
    string str="hello jee";
    stack<char> st2;
    for (auto e:str){
        st2.push(e);
    }
    while(!st2.empty()){
        cout<<st2.top();
        st2.pop();
    }
    cout<<endl;

}