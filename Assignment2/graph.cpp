#include <iostream>
#include "linklist.cpp"

using namespace std;

struct Edge{
    int weight;
    string src, dst;
};

class Graph{
    public:
      // the following are as before
      int numEdges;
      LinkedList<Edge> edges;
      Graph(){ // constructor
            numEdges = 0;
      }

      void newEdge(int weight, string src, string dst){
            Edge edge;
            edge.weight = weight;
            edge.src = src;
            edge.dst = dst;
            edges.Insert(edge);
            numEdges++;
      }

    private:
      //struct Vertex;

      /*struct Vertex{
          string name;
          int numEdges;
          LinkedList<Edge> edges;
      };*/
};

