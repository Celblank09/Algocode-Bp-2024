#include <bits/stdc++.h>

using namespace std;

void BFS(long long v, vector <vector <long long>> &d, vector<vector <pair<long long, bool>>> &G) {
    d[v][0] = 0;
    d[v][1] = 0;
    queue <pair<long long, bool>> q;
    q.push({v, 0});
    while (!q.empty()) {
        auto [v, t_p] = q.front();
        q.pop();
        for (auto [u, t] : G[v]) {
            if (d[v][t_p] + 1 < d[u][t] && t != t_p) {
                d[u][t] = d[v][t_p] + 1;
                q.push({u, t});
            }
        }
    }
    q.push({v, 1});
    while (!q.empty()) {
        auto [v, t_p] = q.front();
        q.pop();
        for (auto [u, t] : G[v]) {
            if (d[v][t_p] + 1 < d[u][t] && t != t_p) {
                d[u][t] = d[v][t_p] + 1;
                q.push({u, t});
            }
        }
    }
}

int main() {
    long long n, m, v, u, t;
    cin >> n >> m;
    vector <vector <long long>> d(n, vector <long long> (2, INT64_MAX));
    vector<vector <pair<long long, bool>>> G(n, vector <pair<long long, bool>>());
    for (int i = 0; i < m; ++i) {
        cin >> v >> u >> t;
        G[u - 1].push_back({v - 1, t - 1});
    }
    BFS(n - 1, d, G);
    for (int i = 0; i < n - 1; ++i) {
        if (min(d[i][0], d[i][1]) == INT64_MAX) {
            cout << -1 << " ";
        } else {
            cout << min(d[i][0], d[i][1]) << " ";
        }
    }
}
