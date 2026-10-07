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
void topoBFS(){
    vector<int> indegree(v, 0);
    for(int i = 0; i < v; i++){
        for(auto neighbour : graph[i]){
            indegree[neighbour]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    cout << "Topological Sort using BFS: ";
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        count++;
        for(auto neighbour : graph[node]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    cout << endl;
    if(count != v){
        cout << "Cycle exists, Topological Sort not possible." << endl;
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
    topoBFS();
    return 0;
}