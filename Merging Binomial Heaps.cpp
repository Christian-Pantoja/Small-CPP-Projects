#include <iostream>
#include <stack>
#include <queue>
#include <cmath>


using namespace std;

struct Node{ //data structure (node)
  Node *parent;
  Node *kid;
  Node *cousin;
  int info;
  int data;
};

typedef Node *PNode;

class BinomialHeap{ //Binomial heap data structure
private:
  PNode head; //points to the root
//-----------------------------------------------------------------------------------
//NAME:               nodeInitialize
//INPUT Param.:       nodes
//OUTPUT Param.:      nullptr
//PURPOSE:            all of the values are initialized to the default
  void nodeInitialize(PNode node, int info, int data){
    node->info = info;
    node->data = data;
    node->parent = 0;
    node->kid = 0;
    node->cousin = 0;
  }
//-----------------------------------------------------------------------------------
//NAME:               TreeLink
//INPUT Param.:       degree
//OUTPUT Param.:      A link between the binomial trees
//PURPOSE:            linkes the two binomial trees with the same degree
  static void TreeLink(PNode x, PNode y){
    y->parent = x;
    y->cousin = x->kid;
    x->kid = y;
    x->data += 1;
  }

public:
//-----------------------------------------------------------------------------------
//NAME:               HeapA
//INPUT Param.:       nodes
//OUTPUT Param.:      Heap tree
//PURPOSE:            creates the first heap tree that I put random node inputs in
  void HeapA(){
    PNode node_1 = new Node;
    nodeInitialize(node_1, 10, 0);
    head = node_1;

    PNode node_2 = new Node;
    nodeInitialize(node_2, 7, 1);

    PNode node_3 = new Node;
    nodeInitialize(node_3, 25, 0);

    node_2->kid = node_3;
    node_3->parent = node_2;
    head = node_2;

    PNode node_4 = new Node;
    nodeInitialize(node_4, 8, 2);

    PNode node_5 = new Node;
    nodeInitialize(node_5, 9, 1);

    PNode node_6 = new Node;
    nodeInitialize(node_6, 15, 0);

    PNode node_7 = new Node;
    nodeInitialize(node_7, 12, 0);

    node_4->kid = node_5;
    node_5->parent = node_4;
    node_6->parent = node_4;
    node_5->kid = node_7;
    node_5->cousin = node_6;
    node_7->parent = node_5;

    node_1->cousin = node_2;
    node_2->cousin = node_4; //links the heap trees
  }

  BinomialHeap(){
    head = 0;
  }

  PNode MinSearch(){ //find the minimum
    int min = 100;
    PNode current = head;
    PNode minimum = 0;

    while (current != 0){
      if (current->info < min){ //traverse the roots
        min = current->info;
        minimum = current;
      }
      current = current->cousin;
    }
    return minimum;
  }
//-----------------------------------------------------------------------------------
//NAME:               HeapB
//INPUT Param.:       Nodes
//OUTPUT Param.:      Heap tree
//PURPOSE:            creates the second tree to unite with HeapA. (as well as initializing all of the nodes).
  void HeapB(){
    PNode node_1 = new Node;
    nodeInitialize(node_1, 17, 0);
    head = node_1;

    PNode node_2 = new Node;
    nodeInitialize(node_2, 5, 1);

    PNode node_3 = new Node;
    nodeInitialize(node_3, 20, 0);

    node_2->kid = node_3;
    node_3->parent = node_2;
    head = node_2;
    node_1->cousin = node_2;

  //initializing all of the nodes:
    PNode node_4 = new Node;
    nodeInitialize(node_4, 9, 4);

    PNode node_5 = new Node;
    nodeInitialize(node_5, 8, 3);

    PNode node_6 = new Node;
    nodeInitialize(node_6, 11, 2);

    PNode node_7 = new Node;
    nodeInitialize(node_7, 16, 1);

    PNode node_8 = new Node;
    nodeInitialize(node_8, 33, 0);
    
    PNode node_9 = new Node;
    nodeInitialize(node_9, 29, 2);
    
    PNode node_10 = new Node;
    nodeInitialize(node_10, 13, 1);

    PNode node_11 = new Node;
    nodeInitialize(node_11, 22, 0);

    PNode node_12 = new Node;
    nodeInitialize(node_12, 13, 1);

    PNode node_13 = new Node;
    nodeInitialize(node_13, 19, 0);

    PNode node_14 = new Node;
    nodeInitialize(node_14, 24, 0);

    PNode node_15 = new Node;
    nodeInitialize(node_15, 34, 1);

    PNode node_16 = new Node;
    nodeInitialize(node_16, 37, 0);

    PNode node_17 = new Node;
    nodeInitialize(node_17, 21, 0);

    PNode node_18 = new Node;
    nodeInitialize(node_18, 19, 0);

    PNode node_19 = new Node;
    nodeInitialize(node_19, 40, 0);

    node_4->kid = node_5;
    node_4->kid = node_6;
    node_4->kid = node_7;
    node_4->kid = node_8; //node 4 connection

    node_5->parent = node_4;
    node_6->parent = node_4;
    node_7->parent = node_4;
    node_8->parent = node_4;

    node_5->kid = node_9;
    node_5->kid = node_10;
    node_5->kid = node_11; //node 5 connection
    node_5->cousin = node_6;

    node_6->kid = node_12;
    node_6->kid = node_13;
    node_6->cousin = node_7;
    
    node_7->kid = node_14;
    node_7->cousin = node_8;

    node_9->parent = node_5; //node 5 connection
    node_10->parent = node_5;
    node_11->parent = node_5;

    node_12->parent = node_6; //node 6 connection
    node_13->parent = node_6;
    node_14->parent = node_7;

    node_9->kid = node_15;
    node_9->kid = node_16;
    node_9->cousin = node_10;
    
    node_10->kid = node_17; //node 10
    node_10->cousin = node_11;

    node_11->cousin = node_12;

    node_12->kid = node_18;
    node_12->cousin = node_13; //node 12

    node_13->cousin = node_14;
    node_13->parent = node_6; //node 13

    node_14->parent = node_7;

    node_15->parent = node_9; //node 15
    node_15->cousin = node_16;

    node_16->parent = node_9;
    node_16->cousin = node_17;

    node_17->parent = node_10;

    node_18->cousin = node_18;//node 18
    node_18->parent = node_12;
    
    node_15->kid = node_19;
    node_19->parent = node_15;

    node_2->cousin = node_4;  
  }

  void NodeInsert(int info){ //insert a node in the heap
    BinomialHeap h;
    PNode node = new Node;
    nodeInitialize(node, info, 0);
    h.setHead(node);
    merge_BinomiaHeap(h);
  }

  void setHead(PNode head){ //head set
    this->head = head;
  }

  PNode getHead(){ //return the head pointer
    return head; 
  }

//-----------------------------------------------------------------------------------
//NAME:               merge_BinomiaHeap
//INPUT Param.:       nodes
//OUTPUT Param.:      merged nodes
//PURPOSE:            to merge both the given HeapA and HeapB together.
  void merge_BinomiaHeap(BinomialHeap h1){
    PNode currentA = getHead();
    PNode currentB = h1.getHead();
    PNode currentC = 0;
    PNode temporary = 0;

    if (currentA->data <= currentB->data){
      currentC = currentA;
      currentA = currentA->cousin;
    }
    else{
      currentC = currentB;
      currentB = currentB->cousin;
    }
    temporary = currentC;

    while(currentA != 0 && currentB !=0){ //merging the two heaps
      if (currentA->data <= currentB->data){
        currentC->cousin = currentA; //the tree is left to right
        currentA = currentA->cousin;
      }
      else{
        currentC->cousin = currentB;
        currentB = currentB->cousin; //the trees have to be gettting greater
      }
      currentC = currentC->cousin;
    }
    if(currentA != 0){ //copying the last of HeapA
      while(currentA!=0){
        currentC->cousin = currentA;
        currentA = currentA->cousin;
        currentC = currentC->cousin;
      }
    }
    if(currentB != 0){ //copying the last of HeapB
      while(currentA !=0){
        currentC->cousin = currentB;
        currentB = currentB->cousin;
        currentC = currentC->cousin;
      }
    }

    currentC = temporary; //scans the merge
    PNode prev = 0;
    PNode next = currentC->cousin;

    while(next !=0){
      if((currentC->data != next->data)|| (next->cousin != 0 && currentC->data == next->cousin->data)){ //moving the trees if they have different degrees
        prev = currentC;
        currentC = next;
      }
      else{
        if(currentC->info <= next->info){ //else merge the binomial tree
          currentC->cousin = next->cousin;
          BinomialHeap::TreeLink(currentC, next);
        }
        else{
          if(prev == 0){
            temporary = next;
          }
          else{
            prev->cousin = next;
          }
          BinomialHeap::TreeLink(next, currentC);
          currentC = next;
        }
      }
      next = currentC->cousin;
    }
    setHead(temporary);
  }
//-----------------------------------------------------------------------------------
//NAME:               printHeap()
//INPUT Param.:       nodes(data)
//OUTPUT Param.:      A list from left to right of the nodes in the new tree
//PURPOSE:            To print the Nodes of the new merged Binomial Tree.
  void printHeap(){
    PNode current = head;
    while(current != 0){
      cout<<"The trees now combined have a new amount of nodes in the Binomial tree:"<<endl;
      cout<<pow(2, current->data)<<endl; //how many nodes

      cout<<"The order of which each node in the Binomial tree is visited (left to right):"<<endl;
      queue<PNode>q; //nodes from left to right
      
      q.push(current);
      while(!q.empty()){
        PNode parent = q.front();
        q.pop();
        cout<<parent->info<<"->";

        if(parent->kid != 0){
          PNode Ptemporary = parent->kid;
          while (Ptemporary != 0){
            q.push(Ptemporary);
            Ptemporary = Ptemporary->cousin;
          }
        }
      }
      cout<<"NULL"; //last node
      cout<<endl;
      current = current->cousin;
    }
  }
};

int main(){
  BinomialHeap firstHeap;
  BinomialHeap secondHeap;
  BinomialHeap UnitedHeap;
  firstHeap.HeapA();
  secondHeap.HeapB();
  firstHeap.merge_BinomiaHeap(secondHeap);
  firstHeap.printHeap();
  return 0;
}
