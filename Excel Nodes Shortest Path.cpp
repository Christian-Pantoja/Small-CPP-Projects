#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//-----------------------------------------------------------------------------------
//NAME:               Shortest_Distance
//INPUT Param.:       integers, an Array
//OUTPUT Param.:      the distance from the source node for each destination 
//PURPOSE:            to find the shortest distance from the desired source node
void Shortest_Distance(int Array[][4]){
  int Short[4], distance[4], size, job, minimum, source, initial, info;
  cout<<"\nInput the source node to generate the shortest distance (A=0, B=1, C=2, D=3): ";
  cin>>source;

  for(initial = 1; initial <= 4; initial++) //initial distance
    distance[initial] = Array[source][initial];

  distance[source] = 0; //source is 0 when not moving
  Short[source] = 1;
  
  for(info = 2; info <= 4-1; info++){
    minimum = 999; //initial all of the Array members to 999
    for(size = 0; size < 4; size++){
      if(Short[size] == 0 && distance[size] == minimum){
        Short[size] = 1;
      }
      for(job = 0; job<4; job++){
        if(distance[job] > distance[size] + Array[size][job]) //dijkstra's Algorithm
            distance[job] = distance[size] + Array[size][job]; //dijkstra's Algorithm
      }
    }
  }
  
  cout<<"\nShortest Distance from Source Node\n";
  for(initial = 0; initial < 4; initial++)
    if(source==0)
      cout<<"The distance from "<<source<<"('A') to "<<initial<<" is "<<distance[initial]<<endl; 
    else if(source == 1)
      cout<<"The distance from "<<source<<"('B') to "<<initial<<" is "<<distance[initial]<<endl;
    else if(source == 2)
      cout<<"The distance from "<<source<<"('C') to "<<initial<<" is "<<distance[initial]<<endl;
    else if(source == 3)
      cout<<"The distance from "<<source<<"('D') to "<<initial<<" is "<<distance[initial]<<endl;
}


//-----------------------------------------------------------------------------------
//NAME:               Create_Graph
//INPUT Param.:       integers, an Array
//OUTPUT Param.:      all of the rows for the graph
//PURPOSE:            to create the graph with the csv file
void Create_Graph(int Array[4][4]){
  float data[16][3];
  ifstream file("Graph.csv"); //reads the extended file
  
  for(int info = 0; info < 16; ++info){
    string line;
    getline(file, line);

    if (!file.good())
      break;

    stringstream store(line); //storing the row

    for (int column = 0; column < 3; ++column){
      string value;
      getline(store, value, ','); //gets all of the values

      if (!store.good())
        break;

      stringstream convertor(value); //converts to integer
      convertor >> data[info][column]; //matrix form
    }
  }
  int A, B, distance;

  for(int row = 0; row < 16; ++row){
    A = data[row][0]; //the first info for the distance matrix
    B = data[row][1]; //the second info for the distance matrix
    distance = data[row][2]; //third info of each row, source to chosen node
    Array[A][B] = distance; //alligns distance to matrix
  }
}

//-----------------------------------------------------------------------------------
//NAME:               Display
//INPUT Param.:       integers, an Array
//OUTPUT Param.:      an array of integers 
//PURPOSE:            to print the graph
void Display(int Array[4][4]){
  for(int info = 0; info < 4; info ++){
    cout<<info;

    for(int job = 0; job < 4; job++){
      cout<<"   "<<Array[info][job]<<"   "; //prints the graph
    }
    cout<<endl;
  }
}

int main(){
  int Array[4][4];
  Create_Graph(Array);
  Display(Array);
  Shortest_Distance(Array);
  return 0;
}