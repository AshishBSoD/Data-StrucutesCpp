#include <iostream>
#include <conio.h>

using namespace std;

void insertNode();
void deleteNode();
void updateNode();
void searchNode();
void printLL();

class Dnode
{
public:
    int data;
    Dnode *next;
    Dnode *prev;
} *head = NULL;

int main()
{
    int option;
    while (true)
    {
        cout << "           *******MENU*******\n";
        cout << "           1. Print DoublyLinkedList.\n";
        cout << "           2. Insert a new Node.\n";
        cout << "           3. Delete a node.\n";
        cout << "           4. Search a node.\n";
        cout << "           5. Update a node.\n";
        cout << "           6. Exit.\n";
        cin >> option;
        switch (option)
        {
        case 1:
            printLL();
            getch();
            break;
        case 2:
            insertNode();
            getch();
            break;
        case 3:
            deleteNode();
            getch();
            break;
        case 4:
            searchNode();
            getch();
            break;
        case 5:
            updateNode();
            getch();
            break;
        case 6:
            return 0;
        default:
            cout << "Choose valid input\n";
            getch();
            break;
        }
    }
}

void insertNode()
{
    Dnode *newNode = new Dnode();
    cout << "Enter value to insert: ";
    cin >> newNode->data;
    newNode->next = NULL;
    cout << "New value inserted.\n";
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Dnode *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newNode->prev = ptr;
    ptr->next = newNode;
    return;
}

void deleteNode()
{
    cout << "Enter the value to delete from linked list: ";
    int element;
    cin >> element;
    Dnode *currnode;
    currnode = head;
    if (currnode->data == element)
    {
        head = currnode->next;

        currnode->next = NULL;
        head->prev = NULL;
        cout << "Node deleted.\n";
        free(currnode);
        return;
    }
    while (currnode != NULL)
    {
        if (currnode->data == element)
        {
            currnode->next->prev = currnode->prev;
            currnode->prev->next = currnode->next;
            currnode->prev = NULL;
            currnode->next = NULL;
            cout << "Node deleted.\n";
            free(currnode);
            return;
        }
        currnode = currnode->next;
    }
    cout << "No such element present to delete.\n";
    return;
}
void updateNode()
{
    int data;
    cout << "Enter the current value of node: ";
    cin >> data;
    Dnode *transnode;
    transnode = head;
    while (transnode != NULL)
    {
        if (transnode->data == data)
        {
            cout << "Enter new value: ";
            cin >> transnode->data;
            cout << "Value updated.\n";
            return;
        }
        transnode = transnode->next;
    }
    cout << "Element not found in Linked List.\n";
    return;
}
void searchNode()
{
    cout << "Enter the value to search in linked list: ";
    int element;
    cin >> element;
    int count = 1;
    Dnode *transnode;
    transnode = head;
    while (transnode != NULL)
    {
        if (transnode->data == element)
        {
            cout << "Element found at " << count << " position.\n";
            return;
        }
        transnode = transnode->next;
        count++;
    }
    cout << "Element not found in Linked List.\n";
    return;
}
void printLL()
{
    if (head == NULL)
    {
        cout << "Currently LinkedList is empty insert some elements first.\n";
        return;
    }
    cout << "Current DoublyLinkedList: ";
    Dnode *transnode;
    transnode = head;
    while (transnode != NULL)
    {
        cout << transnode->data << "->";
        transnode = transnode->next;
    }
    cout << "NULL\n";
    return;
}
