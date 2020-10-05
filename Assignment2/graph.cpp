/*******************************************************************************************
 Filename: graph.cpp                                  
 Assignment No: 2                                                  
 File Description: Contains graph structure                                 
                                                                  
 Date Last Modified: 10/1/2020

I declare that all material in this assessment task is my work except where there
is clear acknowledgement or reference to the work of others. I further declare that I
have complied and agreed to the CMU Academic Integrity Policy at the University
website.
http://www.coloradomesa.edu/student-services/documents
Submissions that do not include the above academic integrity statements will not be
considered.
Student Name: Jesse Holland UID: 700445452 Date: October 3, 2020
*******************************************************************************************/

#include <iostream>
#include "linklist.cpp"

using namespace std;

struct vertex
{
    string name;
    int nodeNum;
};

struct Edge{
    int weight;
    vertex src, dst;
};

struct Graph{
    public:
      int numVertices;
      int numEdges;
      LinkedList<Edge> edges;
      Graph(){ // constructor
            numVertices = 0;
            numEdges = 0;
      }
      
      //add new edge to graph
      void newEdge(int weight, string srcName, int srcNum, string dstName, int dstNum){
            Edge edge;
            edge.weight = weight;
            edge.src.name = srcName;
            edge.src.nodeNum = srcNum;
            edge.dst.name = dstName;
            edge.dst.nodeNum = dstNum;
            edges.Insert(edge);
            numEdges++;
      }
};

