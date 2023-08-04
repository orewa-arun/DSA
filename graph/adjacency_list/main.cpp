#include<iostream>
#include<vector>

using namespace std;
#define V 3

void add_edge(vector<int> adj[],int s,int d){
    // assuming the graph is bidirectional
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void print_graph(vector<int> adj[],int v){
    for(int i=0; i<v; ++i){
        cout << "Vertex " << i << " : ";
        for(auto x : adj[i]){
            cout << "->" << x;
        }
        cout << endl;
    }
}

int main(){
    // graph
    vector<int> adj[V];

    // add edges(adj,src,des)
    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,1,2);

    // display graph
    print_graph(adj,V);

    return 0;
}