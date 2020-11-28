//Doubly Circular Linked List each node will have two pointer and data.
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

class node
{
public:
    //each node will have 3 things
    //data
    int data;
    //Pointer to next node
    node *next;
    //Pointer to previous node.
    node *prev;
} *head = NULL; //initailizing head pozinter to null.

void insertNode(); //Function to append node in the list.
void deleteNode(); //function to delete specified node from the list.
void printLL();    //Traverse the list and print each node data.
void searchNode(); //Search for a specific data containing node.
void updateNode(); //Update the data of a node.

int main()
{
    int option;
    while (true)
    {
        cout << "           *********MENU*******\n";
        cout << "           1. Print LinkedList.\n";
        cout << "           2. Insert a new node.\n";
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
        system("CLS");    
            break;
        case 2:
            insertNode();
            cout << "New value inserted.\n";
            getch();
            system("CLS");
            break;
        case 3:
            deleteNode();
            getch();
            system("CLS");
            break;
        case 4:
            searchNode();
            getch();
            system("CLS");
            break;
        case 5:
            updateNode();
            getch();
            system("CLS");
            break;
        case 6:
            return 0;
        default:
            cout << "Choose valid input\n";
            getch();
            system("CLS");
            break;
        }
    }
}

void insertNode()
{
    node *newNode = new node();
    cout << "Enter value to insert: ";
    cin >> newNode->data;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }
    node *ptr;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    newNode->prev = ptr;
    head->prev = newNode;
    return;
}

void deleteNode(){
    cout << "Enter the value to delete from linked list: ";
    int element;
    cin >> element;
    node *currnode;
    currnode = head->next;
    //if the first element is to be deleted
    //Go to the last node and update its next pointer to first's->next node
    if (head->data == element)
    {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        currnode = head;
        head = head->next;
        cout << "Node deleted.\n";
        free(currnode);
        return;
    }
    //Transversing the loop until we find node with the element or come at at same position.
    while (currnode != head)
    {
        if (currnode->data == element)
        {
            currnode->prev->next = currnode->next;
            currnode->next->prev = currnode->prev;
            cout << "Node deleted.\n";
            free(currnode);
            return;
        }
        currnode = currnode->next;
    }
    cout << "No such element present to delete.\n";
    return;
    return;
}

void searchNode(){
    cout << "Enter the value to search in linked list: ";
    int element;
    cin >> element;
    int count = 2;
    node *transnode;
    transnode = head->next;
    //if element is found at first position.
    if(head->data == element){
        cout << "Element is found at 1st postiion.\n";
        return;
    }
    //transverse the list until transnode is not equal to head node i.e. until a loop is not completed.
    while (transnode != head)
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

void updateNode()
{
    int data;
    cout << "Enter the current value of node: ";
    cin >> data;
    node *transnode;
    transnode = head->next;
    //if updation is required at first node.
    if (head->data == data)
    {
        cout << "Enter new value: ";
        cin >> head->data;
        cout << "Value updated.\n";
        return;
    }
    while (transnode!= head)
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
    while (transnode->next != head)
    {
        cout << transnode->data << "<=>";
        transnode = transnode->next;
    }
    cout << transnode->data << endl;
    return;
}