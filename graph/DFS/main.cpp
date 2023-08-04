#include<iostream>
// it's a doubly linked list
#include<list>

using namespace std;

class Graph{
    int numVertices;
    list<int> *adjLists;
    bool * visited;

    public:
    Graph(int V);
    void addEdge(int src, int des);
    void DFS(int vertex);
};

// Outline functions
Graph::Graph(int vertices){
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

void Graph::addEdge(int src,int des){
    adjLists[src].push_front(des);
}

void Graph::DFS(int vertex){

    // visited array
    visited[vertex] = true;

    // stack of adjLists
    list<int> adjList = adjLists[vertex];

    // like std::cout
    list<int>::iterator i;

    cout << vertex << " ";

    for(i = adjList.begin(); i != adjList.end(); ++i){
        // * is dereferencing the i
        if(!visited[*i])
            DFS(*i);
    }
}

int main(){
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.DFS(2);
}