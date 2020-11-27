//Linked List
//Operation performed
//Searching/Transversal
//Insertion, Deletion, Updation
#include <iostream>
#include <conio.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
} *head = NULL;

void insertNode();
void deleteNode();
void printLL();
void searchNode();
void updateNode();

int main()
{
    int option;
    while (true)
    {
        cout << "           ******MENU*******\n";
        cout << "           1. Print LinkedList.\n";
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
    node *newNode = new node();
    cout << "Enter value to insert: ";
    cin >> newNode->data;
    newNode->next = NULL;
    cout << "New value inserted.\n";
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return;
}


void deleteNode()
{
    cout << "Enter the value to delete from linked list: ";
    int element;
    cin >> element;
    node *currnode;
    currnode = head;
    node *prevnode;
    //Logic to  delete if first element is to be deleted.
    //Update head node to point at the next element in LL.
    if (currnode->data == element)
    {
        head = currnode->next;
        currnode->next = NULL;
        cout << "Node deleted.\n";
        free(currnode);
        return;
    }
    while (currnode != NULL)
    {
        if (currnode->data == element)
        {
            prevnode->next = currnode->next;
            currnode->next = NULL;
            free(currnode);
            cout << "Node deleted.\n";
            return;
        }
        prevnode = currnode;
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
    node *transnode;
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
    node *transnode;
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
    cout << "Current LinkedList: ";
    node *transnode;
    transnode = head;
    while (transnode != NULL)
    {
        cout << transnode->data << "->";
        transnode = transnode->next;
    }
    cout << "NULL\n";
    return;
}
