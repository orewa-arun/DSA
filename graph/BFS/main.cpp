#include<iostream>
#include<list>

using namespace std;

class Graph{
    bool * visited;
    list<int> * adjLists;
    int numVertices;

    public:
    Graph(int V);
    void add_edge(int src, int des);
    void BFS(int vertex);
};

Graph::Graph(int vertices){
    numVertices = vertices;
    visited = new bool[vertices];
    adjLists = new list<int>[vertices];
}

void Graph::add_edge(int src, int des){
    adjLists[src].push_back(des);
}

list<int>:: iterator i;

void Graph::BFS(int start_vertex){
    for (int i = 0; i< numVertices; ++i){
        visited[i] = false;
    }
    list<int> queue;

    visited[start_vertex] = true;
    queue.push_back(start_vertex);

    list<int>::iterator i;
    cout << "visited : ";

    while(!queue.empty()){
        int currVertex = queue.front();
        cout << currVertex << " ";

        queue.pop_front();

        for(i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i){
            int adjVertex = *i;
            if(!visited[adjVertex]){
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }

    cout << endl;
}

int main(){
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    g.BFS(2);

    return 0;
}