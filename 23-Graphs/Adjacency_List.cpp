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
        for(auto x: graph[i]){
            cout << x << ",";
        }
        cout << endl;
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
    return 0;
}