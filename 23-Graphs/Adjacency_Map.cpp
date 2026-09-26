#include<bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> graph;

void addEdge(int src, int dest, bool bidirectional = true){
    graph[src].insert(dest);

    if(bidirectional){
        graph[dest].insert(src);
    }
}

void display(){
    for(int i = 0; i < graph.size(); i++){
        cout << i << "->";

        for(auto x : graph[i]){
            cout << x << " ";
        }

        cout << endl;
    }
}

int main(){
    int v;
    cin >> v;

    graph.resize(v);

    int e;
    cin >> e;

    while(e--){
        int src, dest, weight;
        cin >> src >> dest >> weight;

        addEdge(src, dest, weight);
    }

    display();

    return 0;
}