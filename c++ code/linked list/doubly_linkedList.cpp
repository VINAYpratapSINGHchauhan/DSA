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

void printLL(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int getLngth(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
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
        head->prev = newnode;
        head = newnode;
    }
}
void insertAtTail(node *&head, node *&tail, int value)
{
    node *newnode = new node(value);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void insertAtPos(node *&head, node *&tail, int value, int pos)
{
    int length = getLngth(head);

    if (pos < 1 || pos > length + 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    // Create new node
    node *newnode = new node(value);

    // Case 1: Empty list
    if (head == NULL)
    {
        head = tail = newnode;
        return;
    }

    // Case 2: Insert at head
    if (pos == 1)
    {
        insertAthead(head, tail, value);
        return;
    }

    // Case 3: Insert at tail
    if (pos == length + 1)
    {
        insertAtTail(head, tail, value);
        return;
    }

    // Case 4: Insert in middle
    node *prevNode = head;
    for (int i = 1; i < pos - 1; i++)
    {
        prevNode = prevNode->next;
    }

    newnode->next = prevNode->next;
    newnode->prev = prevNode;
    prevNode->next->prev = newnode;
    prevNode->next = newnode;
}

void deleteNode(node *&head, node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "empty list" << endl;
        return;
    }
    if (head == tail)
    {
        node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    int length = getLngth(head);
    if (pos > length || pos < 1)
    {
        cout << "invalid deletion " << endl;
        return;
    }
    if (pos == 1)
    {
        // delete from head
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;
    }
    if (pos == length)
    {
        // delete from tail
        node *temp = tail->prev;
        temp->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = temp;
        return;
    }
    // deletion from middle
    node *prevNode = head;
    for (int i = 1; i < pos - 1; i++)
    {
        prevNode = prevNode->next;
    }
    node *temp = prevNode->next;
    prevNode->next = temp->next;
    temp->next->prev = prevNode;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}

int main()
{
    // insertion in doubly linked list
    node *head = NULL;
    node *tail = NULL;
    insertAthead(head, tail, 900);
    insertAthead(head, tail, 800);
    insertAthead(head, tail, 700);
    insertAtTail(head, tail, 1100);
    insertAtPos(head, tail, 1000, 4);
    printLL(head);

    // deletion in doubly linked list
    deleteNode(head, tail, 1); // from head
    printLL(head);
    int n = getLngth(head);
    cout<<n<<endl;
    deleteNode(head, tail, n); // from tail
    printLL(head);
    int m = getLngth(head);
    cout<<m<<endl;
    deleteNode(head, tail, 2); // from middle
    printLL(head);
}