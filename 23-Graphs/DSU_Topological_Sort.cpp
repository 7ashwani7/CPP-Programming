#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> edges;
vector<int> parent;
vector<int> size;
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        return;
    }
    if(size[a] < size[b]){
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
}
void addEdge(int src, int dest){
    edges.push_back({src, dest});
}
int main(){
    int v;
    cin >> v;
    parent.resize(v);
    size.resize(v, 1);
    for(int i = 0; i < v; i++){
        parent[i] = i;
    }
    int e;
    cin >> e;
    while(e--){
        int src, dest;
        cin >> src >> dest;
        addEdge(src, dest);
    }
    for(auto edge : edges){
        int src = edge.first;
        int dest = edge.second;
        if(find(src) == find(dest)){
            cout << "Cycle exists" << endl;
            return 0;
        }
        unite(src, dest);
    }
    cout << "No Cycle" << endl;
    return 0;
}