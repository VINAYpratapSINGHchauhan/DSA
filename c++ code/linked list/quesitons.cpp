#include <iostream>
using namespace std;
class node 
{
public:
    int val;
    node *next;
    node(){
        this->next;
    }
    node(int data){
        this->val=data;
        this->next=NULL;
    }
};
void insertAthead(node *&head, node *&tail, int value)
{
    node *newnode = new node(value);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void printLL(node *head)
{
    node *temp = head; // point to be noted
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
node* startingPointOfLoop(node*head){
    //chech the loop and slow fast ko ek jgh pr aa jayga
    node*slow=head;
    node*fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        //loop is present thne they will surely meet at one place
        if(fast==slow){
            break;
        }
    }
    //slow and fasty are at same place
    slow=head;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
void removeLoop(node*head){
    node*startPoint=startingPointOfLoop(head);
    node*temp=startPoint;
    while(temp->next!=startPoint){
        temp=temp->next;
    }
    temp->next=NULL;
}
int main()
{
    // 1. reverse a list - LC: 206
    // 2. find middle of the list - LC: 876
    // 3. check palindrome linked list - LC: 234
    // 4. check cycle in a Linked List - LC: 141

    // find starting point of loop - LC: 142 -solution here
    node*head=NULL;
    node*tail=NULL;
    insertAthead(head,tail,10);
    insertAthead(head,tail,20);
    insertAthead(head,tail,30);
    insertAthead(head,tail,40);
    insertAthead(head,tail,50);
    tail->next=head->next;
    // loop is present now finding the starting point of loop through code
    cout<<startingPointOfLoop(head)->val<<endl;
    
    // 5. remove loop from the linked list - LC: 
    removeLoop(head);
    printLL(head);

}