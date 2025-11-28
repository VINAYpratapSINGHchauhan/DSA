#include<iostream>
#include<queue>
using namespace std;
int main(){
    //creating a max heap 
    priority_queue<int>pq;
    pq.push(10);
    pq.push(12);
    pq.push(13);
    pq.push(16);
    pq.push(1);
    pq.push(100);
    cout<<pq.size()<<endl;
    cout<<pq.empty()<<endl;
    cout<<"top element : "<<pq.top()<<endl;
    pq.pop();
    cout<<"top element : "<<pq.top()<<endl;
    pq.pop();
    cout<<"top element : "<<pq.top()<<endl;

    //creating the min heap 
    priority_queue<int,vector<int>,greater<int>>pq2;
    pq2.push(10);
    pq2.push(12);
    pq2.push(13);
    pq2.push(16);
    pq2.push(1);
    pq2.push(100);
    cout<<pq2.size()<<endl;
    cout<<pq2.empty()<<endl;
    cout<<"top element : "<<pq2.top()<<endl;
    pq2.pop();
    cout<<"top element : "<<pq2.top()<<endl;
    pq2.pop();
    cout<<"top element : "<<pq2.top()<<endl;

    

    return 0;
}