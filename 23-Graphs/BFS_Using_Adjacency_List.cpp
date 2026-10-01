#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;

void addEdge(int src, int dest, bool bidirectional = true){
    graph[src].push_back(dest);

    if(bidirectional){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i = 0; i < graph.size(); i++){
        cout << i << "->";
        for(auto x : graph[i]){
            cout << x << ",";
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
        for(auto x : graph[curr]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main(){
    cin >> v;
    graph.resize(v, list<int>());
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