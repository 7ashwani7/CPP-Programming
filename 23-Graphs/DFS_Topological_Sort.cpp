#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
void addEdge(int src, int dest, bool bidirectional = false){
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
void dfs(int node, vector<bool>& visited, vector<int>& ans){
    visited[node] = true;
    for(auto neighbour : graph[node]){
        if(!visited[neighbour]){
            dfs(neighbour, visited, ans);
        }
    }
    ans.push_back(node);
}
void topoDFS(){
    vector<bool> visited(v, false);
    vector<int> ans;
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            dfs(i, visited, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "Topological Sort using DFS: ";
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
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
    topoDFS();
    return 0;
}