#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node()
    {
        this->prev = NULL;
        this->next = NULL;
    }
    node(int val)
    {
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(node * head){
    node * temp =head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int getLngth(node * head){
    node * temp=head;
    int count=0;
    while (temp!=NULL)      
    {
        count++;
        temp=temp->next;
    }
    return count;
    
}
void insertAthead(node*&head, node* &tail, int value){
    node * newnode=new node(value);
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insertAtTail(node*&head, node* &tail, int value){
    node * newnode=new node(value);
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void insertAtPos(node*& head, node*& tail, int value, int pos) {
    int length = getLngth(head);

    if (pos < 1 || pos > length + 1) {
        cout << "Invalid position" << endl;
        return;
    }

    // Create new node
    node* newnode = new node(value);

    // Case 1: Empty list
    if (head == NULL) {
        head = tail = newnode;
        return;
    }

    // Case 2: Insert at head
    if (pos == 1) {
        insertAthead(head,tail,value);
        return;
    }

    // Case 3: Insert at tail
    if (pos == length + 1) {
        insertAtTail(head,tail,value);
        return;
    }

    // Case 4: Insert in middle
    node* prevNode = head;
    for (int i = 1; i < pos - 1; i++) {
        prevNode = prevNode->next;
    }

    newnode->next = prevNode->next;
    newnode->prev = prevNode;
    prevNode->next->prev = newnode;
    prevNode->next = newnode;
}

int main()
{
    node *head= NULL;
    node *tail= NULL;
    insertAthead(head,tail,900);
    insertAthead(head,tail,800);
    insertAthead(head,tail,700);
    insertAtTail(head, tail , 1100);
    insertAtPos(head,tail,1000,10);
    printLL(head);
}