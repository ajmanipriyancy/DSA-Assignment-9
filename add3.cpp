#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int,int>>> adj(N+1);
    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    const int INF = 1e9;
    vector<int> dist(N+1, INF);
    dist[K]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,K});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]: adj[u]){
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(dist[i]==INF){ cout << -1; return 0; }
        ans = max(ans, dist[i]);
    }
    cout << ans;
}
