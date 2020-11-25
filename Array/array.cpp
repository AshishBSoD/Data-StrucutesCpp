//Basic operation on 1D array
//Searching/Transversing
//Updation
// Insertion, Deletion

#include <iostream>
#include <cstdlib>

#define SIZE 101 //Maximum capacity.

using namespace std;

void insertAt(int[], int, int);
void deleteAt(int[], int);
void searchElement(int[], int);
void printArr(int[]);

int main(){
  int arr[SIZE];
  int temp;
  cout<<"Enter size of array (<100): ";
  //Storing the size of array at 101 location i.e. 100 index 
  cin>>arr[100];
  //filling array with random elements
  srand(time(0)); 
  for(int i = 0 , j = arr[100]; i<j; i++){
    arr[i]= rand()%100;
  }
  cout<<"Current generated array: ";
  printArr(arr);
  //Menu to access array and opearte on them.
  int option=1;
  while(option){

    cout<<"*********Menu*********\n";
    cout<<"1. Print the array.\n";
    cout<<"2. Search the the array.\n";
    cout<<"3. Insert an element in the array.\n";
    cout<<"4. Delete an element from array.\n";
    cout<<"5. Update an element in the array.\n";
    cout<<"6. Output current size of array and maximum size available.\n";
    cout<<"0. To exit the program.\n";
    cin>>option;
    switch(option){
      case 0:{ 
        return 0;
      }
      case 1:{ 
        printArr(arr);
       break;
      }
      case 2:{
        cout<<"Enter element to find in the array: ";
        cin>>temp;
        searchElement( arr, temp);
        break;
      }
      case 3:{
        if(arr[100]==(SIZE-1)){
          cout<<"Array already full.";
          break;
        }
        ++arr[100];
        cout<<"Enter an element to insert in the array: ";
        cin>>temp;
        cout<<"Enter the index at which you want to insert: ";
        int position;
        cin>>position;
        /*//If the position is greater than current array size and less the max size available then the element will be inserted at last."*/
        if((position)>= arr[100]&& position <(SIZE-1)){
          position = (arr[100]-1);
        }
        else if(position> SIZE-1) {
          cout<<"Position not valid.";
        break;
        }
        insertAt(arr, temp, position);
        break;
      }
      case 4:{
        cout<<"Enter index at which you want to delete element: ";
        cin>>temp;
        deleteAt(arr, temp);
        --arr[100];
        break;
      }
      case 5:{
        cout<<"Enter index at which you want to update element: ";
        cin>>temp;
        cout<<"Enter new element at "<<temp<<" :";
        cin>>arr[temp];
        break;
      }
      case 6:{
        cout<<"Current size of array: "<<arr[100]<<endl;
        cout<<"Maximum Size available: "<<(SIZE-1)<<endl;
        break;
      }
      default : {
        cout<<"Provide Valid input.";
      }
    }
  }
}

void printArr(int arr[]){
  for(int i = 0, j =arr[100]; i<j; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
//Performs a linear search to find the given element in the array.
/*
Transverse the array and check each element if it is equal to the requried elemet and if it's found give its index.
This will give the first instance of element in the array as duplicates can be present.*/
void searchElement(int arr[], int ele){
  for(int i = 0 , j= arr[100]; i<j; i++) {
    if(ele == arr[i]){
      cout<<"Element found at Position : "<<i+1;
      return ;
    }
  }
  cout<<"No such element found in the array.\n";
}

//Insert element in the array.
/* Logic
First increase the size of array by one and then starting from last fill 
elemnet of consecutive left size in it and do this till the given position and its right side 
position have same element and the modify the given position 
with the element you want to insert.
Thus shifting all the element to right side from the inserted element position.
*/
void insertAt(int arr[], int element, int position){
  for(int j = position, i=arr[100]-1;j<i ;--i){
    arr[i] = arr[i-1];
  }
  arr[position]= element;
}

//Delete element from array at a given index.
/* 
Start from the given index that we want to delete and fill its position by the next consecutive
right positioned element and do this till all the elements have shifted to left by one.
Thus the given positioned element will be overwritten by its right consecutive positioned element 
and thus is removed from the array
*/
void deleteAt(int arr[], int position){
  for(int i=position, j = arr[100]; i<j ; ++i){
    arr[i] = arr[i+1];
  }
}
