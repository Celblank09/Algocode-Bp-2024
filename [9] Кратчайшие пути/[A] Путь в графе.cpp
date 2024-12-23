#include <bits/stdc++.h>

using namespace std;

void BFS(long long v, vector<vector <long long>> &G, queue <long long> &q, vector <long long> &dist) {
    dist[v] = 0;
    q.push(v);
    while (!q.empty()) {
        long long u = q.front();
        q.pop();
        for (long long k : G[u]) {
            if (dist[u] + 1 < dist[k]) {
                dist[k] = dist[u] + 1;
                q.push(k);
            }
        }
    }
}

int main() {
    long long n, u, v, dop;
    cin >> n;
    vector<vector <long long>> G(n, vector <long long> ());
    queue <long long> q;
    vector <long long> dist(n, INT64_MAX);
    for (long long y = 0; y < n; ++y) {
        for (long long x = 0; x < n; ++x) {
            cin >> dop;
            if (dop) {
                G[y].push_back(x);
            }
        }
    }
    cin >> u >> v;
    u--;
    v--;
    BFS(u, G, q, dist);
    if (dist[v] == INT64_MAX) {
        cout << -1;
    } else {
        cout << dist[v];
    }
}
