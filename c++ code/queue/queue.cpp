#include <iostream>
#include <queue>
using namespace std;
class que
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    que(int s)
    {
        arr = new int[s];
        this->size = s;
        this->front = -1;
        this->rear = -1;
    }
    void push(int val)
    {
        if (rear == size - 1)
        {
            // queue if full
            cout << "overflowL: queue is full" << endl;
            return;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                // empty queue is threr
                front++, rear++;
                arr[front] = val;
                return;
            }
            else
            {
                rear++;
                arr[rear] = val;
                return;
            }
        }
    }
    void pop()
    {
        if (front == -1 && rear == -1)
        {
            // queue is empty
            cout << "underflow: queue is empty" << endl;
        }
        else
        {
            if (front == rear)
            {
                // single element in queue
                arr[front] = -1;
                front = rear = -1;
                return;
            }
            else
            {
                // normal popping
                arr[front] = -1;
                front++;
                return;
            }
        }
    }
    bool empty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getSize()
    {
        if (front == -1 && rear == -1)
            return 0;
        return (rear - front + 1);
    }
    int getFront()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }
    int getBack()
    {
        if (rear == -1)
            return -1;
        return arr[rear];
    }
    void print()
    {
        cout << "printing queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{

    // BY STL
    //creation
    queue<int> q;
    //insertion
    q.push(5);
    q.push(55);
    q.push(555);
    q.push(5555);

    cout<<"size: "<<q.size()<<endl;
    cout<<"front: "<<q.front()<<endl;
    cout<<"back: "<<q.back()<<endl;
    //deletion from front
    q.pop();
    cout<<"popped"<<endl;
    cout<<"front: "<<q.front()<<endl;
    cout<<"back: "<<q.back()<<endl;
    q.pop();
    cout<<"popped"<<endl;
    cout<<"front: "<<q.front()<<endl;
    cout<<"back: "<<q.back()<<endl;
    // empty case
    if(q.empty()) cout<<"empty"<<endl;
    // printing queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    // // implementing queue from scratch
    // que q(5);
    // q.print();
    // cout << q.empty() << endl;
    // cout << q.getFront() << endl;
    // cout << q.getBack() << endl;
    // cout << q.getSize() << endl;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // q.print();
    // cout << q.getFront() << endl;
    // cout << q.getBack() << endl;
    // cout << q.getSize() << endl;
    // q.pop();
    // q.pop();
    // q.print();
    // q.push(60);
    // cout << q.getFront() << endl;
    // cout << q.getBack() << endl;
    // cout << q.getSize() << endl;
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.print();
    // cout<<q.getSize();
    // end of linear queue
    
    // circular queue
    // here the size of the queue is rear-front +1 and if space available anywhere in the array it will be used no memory wastage i.e circular queue explanation in notebook
    //un wanted line
}