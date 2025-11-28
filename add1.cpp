#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& g, vector<int>& vis) {
    vis[u] = 1;
    for (int v : g[u]) if (!vis[v]) dfs(v, g, vis);
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> g(V);
    vector<int> vis(V, 0);
    while (E--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            count++;
            dfs(i, g, vis);
        }
    }
    cout << count;
}
