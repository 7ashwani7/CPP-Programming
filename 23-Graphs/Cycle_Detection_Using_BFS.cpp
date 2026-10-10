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
bool cycleBFS(){
    vector<bool> visited(v, false);
    for(int start = 0; start < v; start++){
        if(visited[start]){
            continue;
        }
        queue<pair<int,int>> q;
        q.push({start, -1});
        visited[start] = true;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto neighbour : graph[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push({neighbour, node});
                }
                else if(neighbour != parent){
                    return true;
                }
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
    if(cycleBFS()){
        cout << "Cycle exists";
    }
    else{
        cout << "No Cycle";
    }
    return 0;
}