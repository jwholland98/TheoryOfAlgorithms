
/*******************************************************************************************
 Filename: MST.cpp                                  
 Assignment No: 2                                                  
 File Description: Builts minimum spanning tree from input file "distances.txt" using
 Kruskal's algorithm or returns shortest path between two cities within "distances.txt"                             
                                                                  
 Date Last Modified: 10/1/2020                                  

I declare that all material in this assessment task is my work except where there
is clear acknowledgement or reference to the work of others. I further declare that I
have complied and agreed to the CMU Academic Integrity Policy at the University
website.
http://www.coloradomesa.edu/student-services/documents
Submissions that do not include the above academic integrity statements will not be
considered.
Student Name: Jesse Holland UID: 700445452 Date: October 1, 2020
*******************************************************************************************/

#include <iostream>
#include <fstream>
#include "graph.cpp"
#include "array.cpp"

using namespace std;

struct subset{
    int parent;
    int rank;
};

int find(Array<subset> &subsets, int i){
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

void Union(Array<subset> &subsets, int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

LinkedList<Edge> Kruskal(Graph graph, bool output){
    int V = graph.numVertices;
    LinkedList<Edge> result;
    int e = 0, i = 0, totaldist = 0;

    Array<subset> subsets(V);
    for (int v=0;v < V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    graph.edges.SetIterator(true);
    while (e < V-1 && i < graph.numEdges){
        Edge next_edge = graph.edges.Next();

        int x = find(subsets, next_edge.src.nodeNum);
        int y = find(subsets, next_edge.dst.nodeNum);

        if (x != y){
            result.InsertBack(next_edge);
            totaldist+=next_edge.weight;
            e++;
            Union(subsets, x, y);
        }
    }
    result.SetIterator(true);
    if (output){
        for (i = 0;i<e;i++){
            Edge edge = result.Next();
            cout << edge.src.name << " to " << edge.dst.name << " :: distance = " << edge.weight << endl;;
        }
        cout << "Total Distance: " << totaldist << endl;
    }
    return result;
}

//builds graph from file specified; returns graph
Graph builtGraph(string fname){
    Graph graph;
    ifstream inf;
    inf.open(fname);
    string city, junk;
    int distance;
    LinkedList<string> cities;

    //get and discard the 2 comments at top of txt file
    getline(inf, junk);
    getline(inf, junk);
    while(getline(inf, city, '[')){//gets city
        if(city[0] == '*')//breaks from loop if comment is found
            break;
        getline(inf, junk);
        cities.SetIterator(true);
        for(int i=graph.numVertices;i>0;i--){//builds edges for each city
            inf >> distance;
            string dstCity = cities.Next();
            graph.newEdge(distance, city, graph.numVertices, dstCity, i-1);
        }
        inf >> ws;//remove extra whitespace
        cities.InsertFront(city);//add city to list of cities
        graph.numVertices++;
    }
    return graph;
}

int main(int argc, char **argv){//make sure to test on ubuntu before submitting
    if (argc < 2)
        cerr << "Usage error" << endl;
    string src, dst;
    if (argc > 2){//if argc is greater than 2, parse input for journey
        int i = 2;
        string tmpsrc(argv[i]);
        src = tmpsrc;
        while (src.back() != ','){//check until last char is comma, then add one more argument to source city
            src += ' ';
            src += argv[++i];
        }
        src += ' ';
        src += argv[++i];

        //repeat for destination city
        string tmpdst(argv[++i]);
        dst = tmpdst;
        while (dst.back() != ','){
            dst += ' ';
            dst += argv[++i];
        }
        dst += ' ';
        dst += argv[++i];
    }
    Graph graph = builtGraph(argv[1]);

    if(argc == 2)//if argc is 2, get mst and output it
        Kruskal(graph, true);
    else{
        LinkedList<Edge> MST = Kruskal(graph, false);
        cout << src << endl << dst << endl;
        //dijkstra
    }
    return 0;
}

    //[DEBUG]
    /*graph.edges.SetIterator(true);
    for(int i=0;i<graph.numEdges;i++){
        Edge edge = graph.edges.Next();
        cout << "Edge " << i+1 << ':' << endl;
        cout << "   Src: " << edge.src.name << endl;
        cout << "   SrcNum: " << edge.src.nodeNum << endl;
        cout << "   Dest: " << edge.dst.name << endl;
        cout << "   DestNum: " << edge.dst.nodeNum << endl;
        cout << "   Distance: " << edge.weight << endl;
    }*/