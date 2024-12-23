#include <bits/stdc++.h>

using namespace std;

void dijkstra(int v, vector<vector<pair<int, long long>>> &G, vector<long long> &dist,
              vector<pair <int, long long>> &predok, int n) {
    dist[v] = 0;
    set <pair <long long, int>> a;
    a.insert({0, v});
    while (!a.empty()) {
        int u = a.begin() -> second;
        a.erase(a.begin());
        for (auto [k, w] : G[u]) {
            if (dist[k] > dist[u] + w) {
                a.erase({dist[k], k});
                predok[k] = {u, predok[u].second + 1};
                dist[k] = dist[u] + w;
                a.insert({dist[k], k});
            }
        }
    }
}

vector<vector<pair<int, long long>>> G(100000, vector<pair<int, long long>>());
vector<long long> dist(100000, INT64_MAX);
vector<pair <int, long long>> predok(100000, {-1, 0});

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, b, e, w;
    cin >> n >> m;
    cin >> v >> u;
    v--;
    u--;
    swap(u, v);
    for (long long i = 0; i < m; ++i) {
        cin >> b >> e >> w;
        b--;
        e--;
        G[b].push_back({e, w});
        G[e].push_back({b, w});
    }
    dijkstra(v, G, dist, predok, n);
    if (dist[u] == INT64_MAX) {
        cout << -1;
        return 0;
    }
    cout << dist[u] << "\n";
    cout << predok[u].second + 1 << "\n";
    while (u != -1) {
        cout << u + 1 << " ";
        u = predok[u].first;
    }
}
