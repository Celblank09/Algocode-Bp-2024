#include <bits/stdc++.h>

using namespace std;

void BFS(long long v, vector<vector<pair<long long, long long>>> &G, queue<long long> &q, vector<long long> &dist) {
    dist[v] = 0;
    q.push(v);
    while (!q.empty()) {
        long long u = q.front();
        q.pop();
        for (auto k : G[u]) {
            if (dist[u] + k.second < dist[k.first]) {
                dist[k.first] = dist[u] + k.second;
                q.push(k.first);
            }
        }
    }
}

vector<vector<pair<long long, long long>>> G(100, vector<pair<long long, long long>>());
vector<long long> dist(100, INT64_MAX);
vector<long long> a(100, 0);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, b, e;
    cin >> n;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    queue<long long> q;
    for (long long i = 0; i < m; ++i) {
        cin >> b >> e;
        b--;
        e--;
        G[b].push_back({e, a[b]});
        G[e].push_back({b, a[e]});
    }
    BFS(0, G, q, dist);
    if (dist[n - 1] == INT64_MAX) {
        cout << -1;
        return 0;
    }
    cout << dist[n - 1] << "\n";
}
