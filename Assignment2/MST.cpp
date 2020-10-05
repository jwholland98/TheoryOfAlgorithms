/*******************************************************************************************
 Filename: MST.cpp                                  
 Assignment No: 2                                                  
 File Description: Builts minimum spanning tree from input file "distances.txt" fromusing
 Kruskal's algorithm and outputs shortest path between two cities within the minimum 
 spanning tree                         
                                                                  
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

/*******************************************************************************************
 1.) False, if every node is increased by a set amount, rather than scaled, paths that
     have more nodes in them get a larger increase in overall weight. This means that
     if a path is faster before the increase, a smaller path might become the new
     shortest path, which is incorrect.

 2.) False, if there are negative weights, they become positive and as such, a path with
     weight that have smaller absolute values could become the new shortest path, which
     is incorrect.

*******************************************************************************************/

#include <iostream>
#include <fstream>
#include "graph.cpp"
#include "array.cpp"

using namespace std;

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

struct subset{
    int parent;
    int rank;
};

//gets parent to check for cycles
int find(Array<subset> &subsets, int i){
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

//combines subsets if edges are now connected
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

//returns Minimum spanning tree of graph represented by an edge list
//Cide based on code from: https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
Array<Edge> Kruskal(Graph graph, bool output){
    int V = graph.numVertices;
    Array<Edge> result(V-1);//stores MST
    int e = 0, i = 0, totaldist = 0;

    Array<subset> subsets(V);//create array for subsets
    for (int v=0;v < V; v++){//set defaults for subsets
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    graph.edges.SetIterator(true);
    while (e < V-1 && i < graph.numEdges){
        Edge next_edge = graph.edges.Next();

        //get the smallest edge
        int x = find(subsets, next_edge.src.nodeNum);
        int y = find(subsets, next_edge.dst.nodeNum);

        //if a cycle is not made, add edge to result
        if (x != y){
            result[e] = next_edge;
            totaldist+=next_edge.weight;
            e++;
            Union(subsets, x, y);
        }
    }
    if (output){//output if output flag is set to true
        for (i = 0;i<e;i++){
            Edge edge = result[i];
            cout << edge.src.name << " to " << edge.dst.name << " :: distance = " << edge.weight << endl;
        }
        cout << "Total Distance: " << totaldist << endl;
    }
    return result;
}

//returns shortest path from a source and destination node within a
//tree structure represented as an edge list
void shortestPathFromTree(Array<Edge> &tree, string src, string dst){
    LinkedList<Edge> result;//stores resulting path
    Array<bool> visited(tree.getSize()+1);//stores nodes already visited
    string next;
    int i=0;
    while(next != dst){//from src node, find path to dst
        if(result.IsEmpty()){//if result is empty, find next path from src node
            if(i>=tree.getSize()-1){
                cerr << "City not found" << endl;
                return;
            }
            if(tree[i].src.name == src){
                result.InsertBack(tree[i]);
                next = tree[i].dst.name;
                visited[tree[i].src.nodeNum] = true;//set both src and dst of edge to visited
                visited[tree[i].dst.nodeNum] = true;
                i=-1;
            }
            else if(tree[i].dst.name == src){
                result.InsertBack(tree[i]);
                next = tree[i].src.name;
                visited[tree[i].src.nodeNum] = true;//set both src and dst of edge to visited
                visited[tree[i].dst.nodeNum] = true;
                i=-1;
            }
        }
        else{//look for next node until end of path is reached, or dst is found
            if(i>=tree.getSize()-1){//if end is reached, go down different path
                Edge tmp = result.PopFromTail();
                if(tmp.src.name == next)//set next to what it was during that time
                    next = tmp.dst.name;
                else
                    next = tmp.src.name;
                i=-1;
            }
            else if(tree[i].src.name == next && visited[tree[i].dst.nodeNum] != true){//if next is found on edge and the node connecting isn't already visited
                result.InsertBack(tree[i]);
                next = tree[i].dst.name;
                visited[tree[i].dst.nodeNum] = true;
                i=-1;
            }
            else if(tree[i].dst.name == next && visited[tree[i].src.nodeNum] != true){//if next is found on edge and the node connecting isn't already visited
                result.InsertBack(tree[i]);
                next = tree[i].src.name;
                visited[tree[i].src.nodeNum] = true;
                i=-1;
            }
        }
        i++;
    }
    result.SetIterator(true);
    for (i = 0;i<result.getSize();i++){
        Edge edge = result.Next();
        cout << "Travel between " << edge.src.name << " and " << edge.dst.name << " :: distance " << edge.weight << endl;
    }
}

int main(int argc, char **argv){
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
    else{//run journey
        Array<Edge> MST = Kruskal(graph, false);
        shortestPathFromTree(MST, src, dst);
    }
    return 0;
}