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

void bfs(int node, vector<bool>& visited){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for(int i = 0; i < v; i++){
            if(graph[curr][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
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
    cout << "BFS: ";
    bfs(0, visited);

    return 0;
}