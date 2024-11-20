#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e15;
const int MAX_N = 1005;

int n, m, start, endd;
int t[MAX_N], c[MAX_N], dist[MAX_N][MAX_N];
vector<pair<int, int>> adj[MAX_N];

void computeShortestPaths(int src) {
    fill(dist[src], dist[src] + MAX_N, INF);
    dist[src][src] = 0;
    set<pair<int, int>> q;
    q.insert({0, src});
    
    while (!q.empty()) {
        int u = q.begin()->second;
        int d = q.begin()->first;
        q.erase(q.begin());
        
        for (auto& [v, weight] : adj[u]) {
            int newDist = d + weight;
            if (newDist < dist[src][v]) {
                q.erase({dist[src][v], v});
                dist[src][v] = newDist;
                q.insert({newDist, v});
            }
        }
    }
}

int dijkstraWithTokenConstraints() {
    vector<int> minCost(MAX_N, INF);
    minCost[start] = 0;
    set<pair<int, int>> q;
    q.insert({0, start});
    
    while (!q.empty()) {
        int u = q.begin()->second;
        int d = q.begin()->first;
        q.erase(q.begin());
        
        for (int v = 1; v <= n; v++) {
            if (dist[u][v] > t[u]) continue;
            int newCost = d + c[u];
            if (newCost < minCost[v]) {
                q.erase({minCost[v], v});
                minCost[v] = newCost;
                q.insert({newCost, v});
            }
        }
    }
    return (minCost[endd] == INF) ? -1 : minCost[endd];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> start >> endd;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        computeShortestPaths(i);
    }
    
    int result = dijkstraWithTokenConstraints();
    cout << result << '\n';

    return 0;
}
