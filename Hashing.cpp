#include <iostream>

using namespace std;

#define memory 9 //defined the memory locations of the table

struct node{ //node struct for all of the entries
  int info;
  struct node *first;
};

struct node *hashtable[memory] = {NULL}; //an array of pointers

//-----------------------------------------------------------------------------------
//NAME:               HashPrint
//INPUT Param.:       integers, 0-8 number table
//OUTPUT Param.:      integers, at the end the table is printed with table and set numbers.
//PURPOSE:            to print the hashtable, 0-8 as well as the given numbers
void HashPrint(){
  struct node *Table;

  for(int i=0; i<memory; i++){ //loop for the memory locations
    cout<<i<<": ";
    Table = hashtable[i];
    if(!Table){
      cout<<"\n";
      continue;
    }
    
    while(Table->first != NULL){ //till last element
      cout<<Table->info<<" -> ";
      Table = Table->first;
    }
    cout<<Table->info<<"\n"; //printing the last element
  }
}

//-----------------------------------------------------------------------------------
//NAME:               Insert
//INPUT Param.:       integers, using the hash equation for the integers provided
//OUTPUT Param.:      integers, specific numbers for the characters.
//PURPOSE:            to insert in hashtable.
void Insert(int key){
  int hash = key % memory; //hashkey function

  struct node * newnode = (struct node *)malloc(sizeof(struct node)); //creating new node
  newnode->info = key;
  newnode->first = NULL;

  if(hashtable[hash] == NULL) //check if empty
    hashtable[hash] = newnode; 

  else{
    struct node *Table = hashtable[hash];

    while(Table->first != NULL){
      Table = Table->first;
    }

    Table->first = newnode;
  }
}

//-----------------------------------------------------------------------------------
//NAME:               Search
//INPUT Param.:       integer, keys
//OUTPUT Param.:      integers, finding the keys in the hashtable, 
//PURPOSE:            to search for the keys in the hashtable.
void Search(int key){
  int hash = key % memory; //findind the hash

  if(hashtable[hash] == NULL) //checking head element
    cout<<"Element not found\n";

  else{
    struct node *Table = hashtable[hash];

    while(Table != NULL){

      if (Table->info== key){ //finding element
        cout<<"Element found\n";
        return;
      }

      Table = Table->first;
    }
    cout<<"Element not found\n";
    return;
  }
}

int main(){
  Insert(7);
  Insert(24);
  Insert(18);
  Insert(52);
  Insert(36);
  Insert(54);
  Insert(11);
  Insert(23);

  HashPrint();

  return 0;
}