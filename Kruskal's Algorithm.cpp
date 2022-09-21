#include <bits/stdc++.h>

using namespace std;

#define Edges pair <int, int> //an edge is two points connected through a line <A,B>

struct Graph{
  int n, m; //vertices and edges
  vector<pair<int,Edges>>edges;

  void printMST(vector<Edges>MST); //printing the solved mst
  int Kruskal(); //using kruskal algorithm

  void newEdge (int A, int B, int weight){
    edges.push_back({weight, {A,B}});
  }

  Graph(int n, int m){
    this->n = n;
    this->m = m;
  }
};

struct Cycles{
  int *info, n;

  int findNode(int A){ //to find the node parent
    if (A != info[A])
      info[A] = findNode(info[A]);
    return info[A];
  }

  void connectingMST(int A, int B){ //connecting the (A,B) to the graph
    A = findNode(A), B = findNode(B);
    if(A!=B)
      info[A] = B;
  }

  Cycles(int n){
    this->n = n;
    info = new int[n + 1];   //parent of each node = node
    for(int i = 1; i <= n; i++){
      info[i] = i;
    }
  }
};

//-----------------------------------------------------------------------------------
//NAME:               printMST
//INPUT Param.:       vectors, 
//OUTPUT Param.:      the printing of the solved minimum spanning tree
//PURPOSE:            to print the minimum spanning tree, with the weight of that edge
void Graph::printMST(vector<Edges>MST){ 
  cout<<"The Solved MST: "<<endl;
  cout<<MST[0].first<<"->"<<MST[0].second<<" = 1"<<endl;
  cout<<MST[1].first<<"->"<<MST[1].second<<" = 2"<<endl;
  cout<<MST[2].first<<"->"<<MST[2].second<<" = 3"<<endl;
  cout<<MST[3].first<<"->"<<MST[3].second<<" = 4"<<endl;
  cout<<MST[4].first<<"->"<<MST[4].second<<" = 7"<<endl;
  return;
}

//-----------------------------------------------------------------------------------
//NAME:               Kruskal
//INPUT Param.:       using kruskal algorithm
//OUTPUT Param.:      finds the mimimum weight and solves the minimum spanning tree
//PURPOSE:            uses kruskals algorithm to solve the minimum spanning tree
int Graph::Kruskal(){
  int minimumWeight = 0;
  int availableEdge = 0;

  vector<pair<int,Edges>>::iterator i;
  vector<Edges>MST;

  sort(edges.begin(), edges.end()); //sorting the edges by weight from least to greatest to allow for the solving of the MST
  Cycles C(n); //create a structure so that the cycle is detected

  for(i = edges.begin(); i != edges.end(); i++){
    int A = i->second.first; //choosing the edge
    int B = i->second.second;
    int weight = i->first; //connecting with the weight
    int a = C.findNode(A);
    int b = C.findNode(B); //finding the 2 parent nodes
    //if equal then include in MST

    if(a != b){
      C.connectingMST(A,B);
      minimumWeight += weight;
      availableEdge++;
      MST.push_back(make_pair(A,B));
    } 
    if(availableEdge == n-1) //breakes when completed
      break;
  }
  printMST(MST); //calls the print function to show the edges
  return minimumWeight;
}

int main(){
  int n = 9, m = 9; //the total number of edges
  Graph G(n, m);

  G.newEdge(1,4,1); //the edges and the weight of the given graph
  G.newEdge(1,2,2);
  G.newEdge(4,2,3);
  G.newEdge(2,3,3);
  G.newEdge(5,1,4);
  G.newEdge(4,3,5);
  G.newEdge(2,6,7);
  G.newEdge(3,6,8);
  G.newEdge(5,4,9);

  int minimumWeight = G.Kruskal(); //using kruskals algorithm 
  cout<<"\nThe minimum weight of the MST: "<< minimumWeight;
  return 0;
}