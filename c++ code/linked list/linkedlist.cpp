#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node()
    {
        this->next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void printLL(node *head)
{
    node *temp = head; // point to be noted
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(node *head)
{
    node *temp = head; // point to be noted
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtBegin(node *&head, int value)
{
    node *newnode = new node(value);
    newnode->next = head;
    head = newnode;
}
void insertAtTail(node *&tail, int value)
{
    node *newnode = new node(value);
    tail->next = newnode;
    tail = newnode;
}
void insertAtPos(node *&head, node *&tail, int value, int pos)
{
    int length = getLength(head);
    cout << "length is : " << length << endl;
    if (pos < 1 || pos > length+1)
    {
        cout << "invalid positon " << endl;
        return;
    }
    if(pos==1){
        insertAtBegin(head, value);
        return;
    }
    if(pos==length+1){
        insertAtTail(tail,value);
        return;
    }
       node *newnode = new node(value);
        // node *prev=NULL;
        // node *curr=head;
        node *prev=head;
        while (pos!=1){
            // prev=curr;
            // curr=curr->next;
            prev=prev->next;
            pos--;
        }
        // prev->next=newnode;
        // newnode->next=curr;
        newnode->next=prev->next;
        prev->next=newnode;
    
}
int main()
{
    // node creation
    //  node head; //static allocation
    node *first = new node(0);
    node *second = new node(5);
    node *third = new node(10);
    node *fourth = new node(15);
    (first->next) = second;
    second->next = third;
    third->next = fourth;
    // linked list created by normal way
    node *head = first;
    node *tail = fourth;
    // printLL(head);
    // int len = getLength(head);
    // cout << "length is : " << len << endl;

    // insertion & deletion in linked list

    // insert at beginiing
    insertAtBegin(head, 100);
    printLL(head);
    // insert an end
    insertAtTail(tail, 500);
    printLL(head);
    // insert at given position
     
    insertAtPos(head, tail, 50, 7);
    printLL(head);
}