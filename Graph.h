#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <queue>
# define INF 0x3f3f3f3f
# define NIL 99999
using namespace std;

class Graph
{
    int V;    // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list<pair<int, int>> *adj;

public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // prints shortest path from s
    void shortestPath(int s, vector<int>& path);

};