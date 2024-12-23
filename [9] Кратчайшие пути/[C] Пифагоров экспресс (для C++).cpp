#include <bits/stdc++.h>

using namespace std;

long long d(int v, int u, vector<pair<long long, long long>> &cities) {
    long long dx = cities[v].first - cities[u].first;
    long long dy = cities[v].second - cities[u].second;
    return dx * dx + dy * dy;
}

void dijkstra(int v, vector<long long> &dist, int n, vector<pair <long long, long long>> &cities) {
    vector <bool> used(n, false);
    dist[v] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        long long min_dist = INT64_MAX;
        for (int k = 0; k < n; ++k) {
            if (!used[k] && dist[k] < min_dist) {
                u = k;
                min_dist = dist[k];
            }
        }
        if (u == -1) {
            return;
        }
        used[u] = true;
        for (int k = 0; k < n; ++k) {
            dist[k] = min(dist[u] + d(k, u, cities), dist[k]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    vector<pair<long long, long long>> cities(n, {0, 0});
    vector<long long> dist(n, INT64_MAX);
    for (long long i = 0; i < n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }
    cin >> u >> v;
    u--;
    v--;
    dijkstra(v, dist, n, cities);
    cout << dist[u] << "\n";
}
