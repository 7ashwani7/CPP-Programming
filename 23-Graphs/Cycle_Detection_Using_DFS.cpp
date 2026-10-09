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
bool dfs(int node, int parent, vector<bool>& visited){
    visited[node] = true;
    for(auto neighbour : graph[node]){
        if(!visited[neighbour]){
            if(dfs(neighbour, node, visited)){
                return true;
            }
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}
bool cycleDFS(){
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            if(dfs(i, -1, visited)){
                return true;
            }
        }
    }
    return false;
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
    if(cycleDFS()){
        cout << "Cycle exists";
    }
    else{
        cout << "No Cycle";
    }
    return 0;
}