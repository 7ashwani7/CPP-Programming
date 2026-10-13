#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pp = pair<ll, int>;
vector<list<pair<int, int>>> gr;
void add_edge(int u, int v, int wt, bool bidir = true) {
    gr[u].push_back({v, wt});
    if (bidir) {
        gr[v].push_back({u, wt});
    }
}
vector<ll> dijkstra(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    vector<ll> dist(n, LLONG_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (wt != dist[node]) continue;
        for (auto x : gr[node]) {
            if (dist[x.first] > wt + x.second) {
                dist[x.first] = wt + x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }
    return dist;
}
int main() {
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    while (m--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        add_edge(u, v, wt);
    }
    int src;
    cin >> src;
    vector<ll> dist = dijkstra(src, n);
    for (int i = 0; i < n; i++) {
        if (dist[i] == LLONG_MAX) cout << i << " INF" << endl;
        else cout << i << " " << dist[i] << endl;
    }
    int dest;
    cin >> dest;
    if (dist[dest] == LLONG_MAX) cout << "No Path" << endl;
    else cout << dist[dest] << endl;
    return 0;
}