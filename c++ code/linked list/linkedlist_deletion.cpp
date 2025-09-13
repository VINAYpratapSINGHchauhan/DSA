#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node(){
        this->next=NULL;
    }
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        cout<<"node deleted "<<this->data<<endl;
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
void insertAtBegin(node *&head, node *&tail, int value) {
    node *newnode = new node(value);
    if(head == NULL){ // empty list
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}
void insertAtTail(node *&head, node *&tail, int value) {
    node *newnode = new node(value);
    if(head == NULL){ // empty list
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
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
void deleteNode(node * &head, node* & tail , int pos){
    if(head==tail){
        //singl element
        node * temp =head ;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    if(head==NULL){
        cout<<"empty list : invalid deletion"<<endl;
        return;
    }
    else{
        int length=getLength(head);
        if(pos<1 || pos>length){
            cout<<"deleting invalid entry "<<endl;
            return;
        }else if (pos==1){ //delete from head
            node * temp=head;
            head=temp->next;
            temp->next=NULL;
            delete temp;
        }else if(pos==length){ //delete from tail
            node * prev=head;
            while (prev->next!=tail){
                prev=prev->next;
            }
            prev->next=NULL;
            delete tail;
            tail=prev;
        }else{ //delete form middle
            node *prev=head;
            while (pos-1!=1){
                prev=prev->next;
                pos--;
            }
            node * temp=prev->next;
            prev->next=temp->next;
            temp->next=NULL;
            delete temp;
        }
    }
}
int main(){
    node *head=NULL;
    node * tail= NULL;
    insertAtBegin(head,tail,100);
    insertAtBegin(head,tail,200);
    insertAtBegin(head,tail,300);
    insertAtBegin(head,tail,400);
    insertAtBegin(head,tail,500);
    deleteNode(head,tail,5);
    printLL(head);
}