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

    return 0;
}