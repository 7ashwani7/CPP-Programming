#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pp = pair<int, int>;
vector<list<pp>> gr;
void add_edge(int u, int v, int wt, bool bidir = true) {
    gr[u].push_back({v, wt});
    if (bidir) {
        gr[v].push_back({u, wt});
    }
}
ll prims(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    vector<bool> vis(n + 1, false);
    vector<int> par(n + 1, -1);
    vector<int> mp(n + 1, INT_MAX);
    pq.push({0, src});
    mp[src] = 0;
    int total_count = 0;
    ll result = 0;
    while (total_count < n && !pq.empty()) {
        pp curr = pq.top();
        pq.pop();
        int wt = curr.first;
        int node = curr.second;
        if (vis[node]) continue;
        vis[node] = true;
        total_count++;
        result += wt;
        for (auto neighbour : gr[node]) {
            int nextNode = neighbour.first;
            int edgeWt = neighbour.second;
            if (!vis[nextNode] && mp[nextNode] > edgeWt) {
                pq.push({edgeWt, nextNode});
                par[nextNode] = node;
                mp[nextNode] = edgeWt;
            }
        }
    }
    return result;
}
int main() {
    int n, m;
    cin >> n >> m;
    gr.resize(n + 1);
    while (m--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        add_edge(u, v, wt);
    }
    int src;
    cin >> src;
    cout << prims(src, n) << endl;
    return 0;
}