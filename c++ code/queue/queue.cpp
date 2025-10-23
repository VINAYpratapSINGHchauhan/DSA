#include <iostream>
#include <queue>
#include <deque>
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
class Cque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Cque(int size)
    {
        arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    void push(int val)
    {
        // case 1: jisme overflow ho rha ho
        if (front == 0 && rear == size - 1 || front == rear + 1)
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            // case 2: first element insert kr rhe h hm
            front++;
            rear++;
            arr[front] = val;
        }
        else if (rear == size - 1 && front != 0)
        {
            // case 3 : circular aage first index pr isert kro
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            // normal pushing
            rear++;
            arr[rear] = val;
        }
    }
    void pop()
    {
        // case 1: popping from empty queue
        if (front == -1 && rear == -1)
        {
            cout << "UNDERFLOW" << endl;
            return;
        }
        else if (front == rear)
        {
            // case 2: popping single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            // case 3 : circular wala
            arr[front] = 0;
            front = 0;
        }
        else
        {
            // normal popping
            arr[front] = 0;
            front++;
        }
    }
    void display()
    {
        cout << "printing queue : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class deq
{
    // normal doubly ended queue
public:
    int *arr;
    int size;
    int front;
    int rear;
    deq(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = -1;
        this->rear = -1;
    }
    void pushback(int val)
    {
        // overflow
        // emptycase
        // normal flow
        if (rear = size - 1)
        {
            cout << "overflow: queue is full" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void pushfront(int val)
    {
        // overflow
        // emptycase
        // normal flow
        if (front ==0)
        {
            cout << "overflow: queue is full" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }
    void popback()
    {
        //underflow
        //sigle element
        //normal
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
                arr[rear] = -1;
                rear--;
                return;
            }
        }
        
    }
    void popfront()
    {
        //underflow
        //sigle element
        //normal
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
};

//circular dequeue 
class CircularDeq
{
    // normal doubly ended queue
public:
    int *arr;
    int size;
    int front;
    int rear;
    CircularDeq(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = -1;
        this->rear = -1;
    }
    void pushback(int val)
    {
        // overflow
        // emptycase
        // normal flow
        // case 1: jisme overflow ho rha ho
        if (front == 0 && rear == size - 1 || front == rear + 1)
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            // case 2: first element insert kr rhe h hm
            front++;
            rear++;
            arr[rear] = val;
        }
        else if (rear == size - 1 && front != 0)
        {
            // case 3 : circular case
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            // normal pushing
            rear++;
            arr[rear] = val;
        }
    }
    void pushfront(int val)
    {
        // overflow
        // emptycase
        // normal flow
        // case 1: jisme overflow ho rha ho
        if (front == 0 && rear == size - 1 || front == rear + 1)
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            // case 2: first element insert kr rhe h hm
            front++;
            rear++;
            arr[front] = val;
        }
        else if (front==0&&rear!=size-1)
        {
            // case 3 : circular case
            front = size-1;
            arr[front] = val;
        }
        else
        {
            // normal pushing
            front--;
            arr[front] = val;
        }
    }
    void popback()
    {
        //underflow
        //sigle element
        //normal
        // case 1: popping from empty queue
        if (front == -1 && rear == -1)
        {
            cout << "UNDERFLOW" << endl;
            return;
        }
        else if (front == rear)
        {
            // case 2: popping single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            // case 3 : circular wala
            arr[rear] = 0;
            rear = size-1;
        }
        else
        {
            // normal popping
            arr[rear] = 0;
            rear--;
        }
        
    }
    void popfront()
    {
        //underflow
        //sigle element
        //normal
        // case 1: popping from empty queue
        if (front == -1 && rear == -1)
        {
            cout << "UNDERFLOW" << endl;
            return;
        }
        else if (front == rear)
        {
            // case 2: popping single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            // case 3 : circular wala
            arr[front] = 0;
            front = 0;
        }
        else
        {
            // normal popping
            arr[front] = 0;
            front++;
        }
    }
};

int main()
{

    // // BY STL
    // //creation
    // queue<int> q;
    // //insertion
    // q.push(5);
    // q.push(55);
    // q.push(555);
    // q.push(5555);

    // cout<<"size: "<<q.size()<<endl;
    // cout<<"front: "<<q.front()<<endl;
    // cout<<"back: "<<q.back()<<endl;
    // //deletion from front
    // q.pop();
    // cout<<"popped"<<endl;
    // cout<<"front: "<<q.front()<<endl;
    // cout<<"back: "<<q.back()<<endl;
    // q.pop();
    // cout<<"popped"<<endl;
    // cout<<"front: "<<q.front()<<endl;
    // cout<<"back: "<<q.back()<<endl;
    // // empty case
    // if(q.empty()) cout<<"empty"<<endl;
    // // printing queue
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    // cout<<endl;

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

    // // CIRCULAR QUEUE
    // // here the size of the queue is rear-front +1 and if space available anywhere in the array it will be used no memory wastage i.e circular queue explanation in notebook
    // Cque cq1(5);
    // cq1.display();
    // cq1.push(10);
    // cq1.push(20);
    // cq1.push(30);
    // cq1.display();
    // cq1.push(40);
    // cq1.push(50);
    // cq1.display();
    // cq1.push(60);
    // cq1.display();
    // cq1.pop();
    // cq1.pop();
    // cq1.pop();
    // cq1.display();
    // cq1.push(60);
    // cq1.push(70);
    // cq1.display();
    // cq1.push(80);
    // cq1.display();
    // cq1.push(90);
    // cq1.display();
    // cq1.pop();
    // cq1.pop();
    // cq1.pop();
    // cq1.display();

    // doubly ended queue
    deque<int> dq;
    dq.push_back(10);
    cout << dq.back() << endl;
    dq.push_back(20);
    cout << dq.front() << " ";
    cout << dq.back() << endl;
    dq.push_front(00);
    cout << dq.front() << " ";
    cout << dq.back() << endl;
    cout << dq.size() << endl;
    dq.pop_back();
    dq.pop_front();
    cout << dq.back() << endl;
    cout << dq.size() << endl;
    // implementing deque from scratch
}