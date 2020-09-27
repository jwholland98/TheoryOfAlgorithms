#include <iostream>
#include <fstream>
#include "graph.cpp"

using namespace std;

int main(){//need to keep in mind later that it stores head and tail as edges which is incorrect
    Graph graph;
    ifstream inf;
    inf.open("distances.txt");
    string city, junk;
    int numCities=0, distance;
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
        cities.Insert(city);
        cities.SetIterator();
        for(int i=0;i<numCities;i++){
            inf >> distance;
            string dstCity = cities.Next();
            graph.newEdge(distance, city, dstCity);
        }
        numCities++;
    }

    //[DEBUG]
    graph.edges.SetIterator();
    for(int i=0;i<graph.numEdges;i++){
        Edge edge = graph.edges.Next();
        cout << "Edge " << i+1 << ':' << endl;
        cout << "   Src: " << edge.src << endl;
        cout << "   Dest: " << edge.dst << endl;
        cout << "   Distance: " << edge.weight << endl;
    }
    return 0;
}