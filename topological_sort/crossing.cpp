#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, n;
        cin >> n;

        vector<int> X(n), Y(n), R(n);
        vector<int> mark_1(n, 0), mark_2(n, 0), vis(n, 0), dist(n, MAX);
        vector<vector<int>> g(n);

        for (int i = 0; i < n; i++) {
            cin >> X[i] >> Y[i] >> R[i];
        }

        cin >> A >> B;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long dist_1 = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
                long long dist_2 = (R[i] + R[j]) * (R[i] + R[j]);

                if (dist_1 <= dist_2) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (abs(Y[i] - A) <= R[i]) mark_1[i] = 1;
            if (abs(Y[i] - B) <= R[i]) mark_2[i] = 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        for (int i = 0; i < n; i++) {
            if (mark_2[i]) {
                Q.push({1, i});
                dist[i] = 1;
            }
        }

        int ans = MAX;

        while (!Q.empty()) {
            auto [cost, id] = Q.top();
            Q.pop();

            if (vis[id]) continue;
            vis[id] = 1;

            if (mark_1[id]) {
                ans = min(ans, cost);
            }

            for (int neighbor : g[id]) {
                if (dist[neighbor] > cost + 1) {
                    dist[neighbor] = cost + 1;
                    Q.push({cost + 1, neighbor});
                }
            }
        }

        if (ans != MAX)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
