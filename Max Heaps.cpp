#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

//-----------------------------------------------------------------------------------
//NAME:               Max_heapify
//INPUT Param.:       integers, the given Array
//OUTPUT Param.:      integers, specific numbers for the characters.
//PURPOSE:            to return the operations as integers, checking them.
void Max_heapify(int Array[], int size, int info){
  int large = info; //largest is root
  int left = 2*info+1;
  int right = 2*info+2;
  if (left < size && Array[left] > Array[large]) //if left child is higher than root
    large = left;
  if (right < size && Array[right] > Array[large]) //if right child is higher than root
    large = right;
  if (large != info){ //if the largest isnt the root
    int comp;
    comp = Array[info];
    Array[info] = Array[large];
    Array[large] = comp; //swap the info array with the large array
    Max_heapify(Array, size, large);
  }
}

//-----------------------------------------------------------------------------------
//NAME:               Build_heap
//INPUT Param.:       integers, the given Array
//OUTPUT Param.:      build the max heap
//PURPOSE:            to return the operations as integers, checking them.
void Build_heap(int Array[], int size){
  int info;
  int pass = (size/2)-1;
  for (info = pass; info >= 0; info--)
    Max_heapify(Array, size, info); //reverse level order traversal from the last non leaf and to heapify the nodes
}

//-----------------------------------------------------------------------------------
//NAME:               Print_Heap
//INPUT Param.:       integers, the given Array
//OUTPUT Param.:      the array is printed 
//PURPOSE:            to print the array in a max heap.
void Print_Heap(int Array[], int length){
  int info, job;
  for (info = 0; info < length; info++){
    for (job = 0; job < (int)pow(2,info) && job + (int)pow(2,info) < length; job++){
      cout<<Array[job + (int)pow(2,info) - 1]<<" ";
    }
    cout<<endl;
  }
}

//-----------------------------------------------------------------------------------
//NAME:               Delete_root
//INPUT Param.:       integer, the array given
//OUTPUT Param.:      Deleting the max root
//PURPOSE:            delete the max root of the max heap
void Delete_root(int Array[], int length){
  int last = Array[length - 1]; //last element
  Array[0] = last; //replace with first
  length = length - 1;
  Max_heapify(Array, length, 0);
}

int main(){
  int Array[] = {28, 12, 17, 5, 7, 22, 13, 12, 4, 11, 16};
  int length = sizeof(Array)/sizeof(Array[0]);
  cout<<"Given Array: 28, 12, 17, 5, 7, 22, 13, 12, 4, 11, 16";
  cout<<"\n\n";
  while(1){ 
     cout<<"1. Build the Max Heap with the given Arrayay. \n2. Print the Max Heap \n3. Delete a root node from the heap. \n4. Exit. \n\nChoose an option: "; //menu
     int menu;
     cin>>menu;
     switch(menu){
       case 1:
          cout<<"\nThe Max Heap has been built";
          Build_heap(Array, length);
          cout<<"\n\n";
          break;
       
       case 2:
          cout<<"\nThe Max Heap: \n";
          Print_Heap(Array, length);
          break;

       case 3:
          cout<<"\nA Root has been deleted";
          Delete_root(Array, length);
          cout<<"\n";
          break;
      
       case 4:
          return 0; //exit

       default:
          cout<< "No menu option applicable";
          break; //wrong number for menu
    }
  }
}