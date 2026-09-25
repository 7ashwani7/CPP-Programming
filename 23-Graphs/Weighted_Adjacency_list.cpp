#include<bits/stdc++.h>
using namespace std;

vector<list<pair<int,int>>> graph;
int v;

void addEdge(int src, int dest, int weight, bool bidirectional = true){
    graph[src].push_back({dest, weight});

    if(bidirectional){
        graph[dest].push_back({src, weight});
    }
}

void display(){
    for(int i = 0; i < graph.size(); i++){
        cout << i << "->";

        for(auto x: graph[i]){
            cout << "(" << x.first << "," << x.second << ") ";
        }
        cout << endl;
    }
}

int main(){
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