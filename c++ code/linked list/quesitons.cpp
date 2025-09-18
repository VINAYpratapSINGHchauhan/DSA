#include <iostream>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node()
    {
        this->next;
    }
    node(int data)
    {
        this->val = data;
        this->next = NULL;
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
node *startingPointOfLoop(node *head)
{
    // chech the loop and slow fast ko ek jgh pr aa jayga
    node *slow = head;
    node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // loop is present thne they will surely meet at one place
        if (fast == slow)
        {
            break;
        }
    }
    // slow and fasty are at same place
    slow = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
void removeLoop(node *head)
{
    node *startPoint = startingPointOfLoop(head);
    node *temp = startPoint;
    while (temp->next != startPoint)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
node *reverseLL(node *head)
{
    node *prev = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        node *nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
}
void addOneToLinkedList(node *&head) {
    head = reverseLL(head);

    int carry = 1;
    node *temp = head;

    while (temp != NULL && carry != 0) {
        int totalSum = temp->val + carry;
        temp->val = totalSum % 10;
        carry = totalSum / 10;
        if (temp->next == NULL && carry != 0) {
            temp->next = new node(carry);
            carry = 0;
        }
        temp = temp->next;
    }

    head = reverseLL(head);
}

int main()
{
    // 1. reverse a list - LC: 206
    // 2. find middle of the list - LC: 876
    // 3. check palindrome linked list - LC: 234
    // 4. check cycle in a Linked List - LC: 141
    // 5. starting point of loop in a Linked List - LC: 142 (solution here also)
    // 6. remove loop from the linked list - GFG  (solution here)
    // 7. add 1 to a linked list number - LC: 369 (solution here)
    // 8. add 2 number represented by linkedlist - LC: 02
    // 9. reverse a linked list in a group of k - LC: 25
    // 10. sort 0,1,2 in linked list - GFG (solution here)
    // 11. remove duplicate in sorted linked list - LC: 83
    // 12. remove duplicate in sorted linked list 2 - LC: 82
    // 13. sort the given linked list - LC: 148

    // 5.  find starting point of loop - LC: 142 -solution here
    node *head = NULL;
    node *tail = NULL;
    insertAthead(head, tail, 9);
    insertAthead(head, tail, 9);
    insertAthead(head, tail, 2);
    // insertAthead(head, tail, 3);
    // insertAthead(head, tail, 4);
    // insertAthead(head, tail, 5);
    tail->next = head->next;
    // loop is present now finding the starting point of loop through code
    cout << startingPointOfLoop(head)->val << endl;

    // 6. remove loop from the linked list - LC:
    removeLoop(head);

    printLL(head);
    // 7. add one to a linked list
    // abhi our linked list is 5->4->3->2->1 and after addition ans should be 5->4->3->2->2
    addOneToLinkedList(head);
    printLL(head);
}