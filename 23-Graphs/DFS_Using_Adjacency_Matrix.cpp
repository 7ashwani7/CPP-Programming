#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int v;

void addEdge(int src, int dest, bool bidirectional = true){
    graph[src][dest] = 1;

    if(bidirectional){
        graph[dest][src] = 1;
    }
}

void display(){
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int node, vector<bool>& visited){
    cout << node << " ";
    visited[node] = true;

    for(int i = 0; i < v; i++){
        if(graph[node][i] == 1 && !visited[i]){
            dfs(i, visited);
        }
    }
}

int main(){
    cin >> v;

    graph.resize(v, vector<int>(v, 0));

    int e;
    cin >> e;

    while(e--){
        int src, dest;
        cin >> src >> dest;

        addEdge(src, dest);
    }

    display();

    vector<bool> visited(v, false);

    cout << "DFS: ";
    dfs(0, visited);

    return 0;
}