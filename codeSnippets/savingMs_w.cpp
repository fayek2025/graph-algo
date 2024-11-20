#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int, long long int> ipair;

const long long INF = 1e15;
const int N = 1005;

vector<ipair> adj[N];
long long dist[N][N]; 
long long t[N], c[N]; 

// Precomputing all-pairs shortest paths using Dijkstra
void computeAllPairsShortestPaths(int n) {
    for (int i = 1; i <= n; ++i) {
        // Initialize distances for source node `i`
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;

        // Dijkstra for node `i`
        priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
        pq.push({0, i});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[i][u]) continue;

            for (auto edge : adj[u]) {
                int v = edge.first;
                long long weight = edge.second;
                if (dist[i][v] > dist[i][u] + weight) {
                    dist[i][v] = dist[i][u] + weight;
                    pq.push({dist[i][v], v});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, start, endd;
    cin >> n >> m >> start >> endd;

    // Reading edges
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Reading stamina and sleep costs
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> c[i];
    }

    // Precompute all-pairs shortest paths
    computeAllPairsShortestPaths(n);

    // Dijkstra-like traversal to find the minimum sleep cost
    vector<long long> minSleep(n + 1, INF);
    set<ipair> pq;

    minSleep[start] = 0;
    pq.insert({0, start});

    while (!pq.empty()) {
        long long sleepCost = pq.begin()->first;
        int node = pq.begin()->second;
        pq.erase(pq.begin());

        for (int next = 1; next <= n; ++next) {
            // Check if the stamina threshold allows transition
            if (dist[node][next] <= t[node]) {
                long long newSleepCost = sleepCost + c[node];
                if (newSleepCost < minSleep[next]) {
                    pq.erase({minSleep[next], next});</ipair></long></ipair></ipair></ipair></long>
                    minSleep[next] = newSleepCost;
                    pq.insert({newSleepCost, next});
                }
            }
        }
    }

    // Output the result
    if (minSleep[endd] == INF) {
        cout << -1 << endl;
    } else {
        cout << minSleep[endd] << endl;
    }

    return 0;
}
