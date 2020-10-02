
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

using namespace std;

struct subset{
    int parent;
    int rank;
};

int find(subset subsets[], int i){
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void Kruskal(Graph graph){
    int V = graph.numVertices;
    LinkedList<Edge> result;
    int e = 0, i = 0;

    subset *subsets = new subset[(V * sizeof(subset))];
    
    for (int v=0;v < V; ++v){//try v++ later, just out of curiosity
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
            e++;
            Union(subsets, x, y);
        }
    }
    result.SetIterator(true);
    for (i = 0;i<e;++i){//lol, same as above
        Edge edge = result.Next();
        cout << edge.src.name << " to " << edge.dst.name << " :: distance = " << edge.weight << endl;;
    }
    delete subsets;
}

int main(int argc, char **argv){//need to change to get state as well as city name
    if (argc<2 || argc > 4)
        cerr << "Usage error" << endl;
    Graph graph;
    ifstream inf;
    inf.open(argv[1]);
    string city, junk;
    int distance;
    LinkedList<string> cities;
    inf >> junk >> junk >> junk >> junk >> junk >> junk >> junk >> junk >> junk;//get and discard the 2 comments at top of txt file
    while(inf >> city){//gets city
        if(city == "*")
            break;
        while(city.back() != ','){//handles spaces in names
            string tmp;
            inf >> tmp;
            city = city + " " + tmp;
        }
        inf >> junk; // gets and discards junk after city name
        city.pop_back();//removes comma from city name
        cities.SetIterator(true);
        for(int i=graph.numVertices;i>0;i--){//builds edges for each city
            inf >> distance;
            string dstCity = cities.Next();
            graph.newEdge(distance, city, graph.numVertices, dstCity, i-1);
        }
        cities.InsertFront(city);
        graph.numVertices++;
    }
    Kruskal(graph);

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
    return 0;
}