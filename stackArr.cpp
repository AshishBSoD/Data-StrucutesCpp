//Implementing stack using array.
#include <iostream>

#define SSIZE 50

using namespace std;

//Pop operation to get the top element and remove from the stack.
int pop();
//Push operation to append an element at the top.
void push();
//Peek operation to see the elements without removing them from the stack.
void peek();
//To check the state of array is empty or not.
bool isEmpty();

int top = -1; //Points at the top element of stack.
int stack[SSIZE]; //Size of stack

int main(){
    cout << "*********MENU*********\n";
    cout << "         1. Push.\n";
    cout << "         2. Pop.\n";
    cout << "         3. Peek.\n";
    cout << "         4. isEmpty.\n";
    cout << "         5. Exit.\n";
    int option;
    int ele=0;
    while(true){
    cin >> option;
        switch (option)
        {
        case 1:
            push();
            break;
        case 2:
            ele = pop();
            break;
        case 3:
            peek();
            break;
        case 4:
         cout<< "Stack Status\n 1 for empty.\n 0 for Non empty.\n Empty: "<<isEmpty()<<endl;
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "Choose valid input.\n";
            break;
        }
    }
}

void push(){
    if(top== (SSIZE-1)) {
        cout << "Stack already full.\n";
        return;
    }
    int ele;
    cout << "Enter element to push: ";
    cin >> ele;
    stack[++top] = ele;
    cout << "Element pushed into stack.\n";
}

int pop(){
    if(isEmpty()){
        cout << "No element to pop stack empty.\n";
        return 0;
    }
    cout << "Top element popped.\n";
    return stack[top--];
}

void peek(){
    if(isEmpty()){
        cout << "Empty stack.\n";
        return;
    }
    cout << "Current element in stack are: ";
    for (int i = 0; i <= top; i++){
        cout << stack[i] << " ";
    }
    cout << endl;
}

bool isEmpty(){
    return (top == -1);
}