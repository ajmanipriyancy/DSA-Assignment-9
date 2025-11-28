#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> vis(n, 0);
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, 0, -1});
    int total = 0;
    while (!pq.empty()) {
        auto [w, u, p] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        total += w;
        for (auto& pr : adj[u]) pq.push({pr.second, pr.first, u});
    }
    cout << total;
}
