#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<vector<ll>> grid(m, vector<ll>(n));
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cin >> grid[i][j];
    const ll INF = (1LL<<60);
    vector<vector<ll>> dist(m, vector<ll>(n, INF));
    priority_queue< tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> pq;
    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], 0, 0});
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
    while (!pq.empty()) {
        auto [d, r, c] = pq.top(); pq.pop();
        if (d != dist[r][c]) continue;
        if (r == m-1 && c == n-1) break;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            ll nd = d + grid[nr][nc];
            if (nd < dist[nr][nc]) {
                dist[nr][nc] = nd;
                pq.push({nd, nr, nc});
            }
        }
    }
    cout << dist[m-1][n-1] << "\n";
    return 0;
}
