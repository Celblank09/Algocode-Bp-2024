#include <bits/stdc++.h>

using namespace std;

void add(long long v, vector<bool> &used, vector<vector<pair<long long, long long>>> &G, vector<long long> &mx,
         vector<long long> &mv, set <pair <long long, long long>> &a) {
    used[v] = true;
    a.erase({mx[v], v});
    for (auto i : G[v]) {
        if (used[i.first]) {
            continue;
        }
        if (mx[i.first] > i.second) {
            a.erase({mx[i.first], i.first});
            mx[i.first] = i.second;
            mv[i.first] = v;
            a.insert({mx[i.first], i.first});
        }
    }
}

int main() {
    long long n, m, v, u, w;
    cin >> n >> m;
    vector <pair <int, int>> res;
    vector <pair <long long, long long>> edges;
    vector<vector<pair<long long, long long>>> G(n, vector<pair<long long, long long>> ());
    set <pair <long long, long long>> a;
    vector<long long> mx(n, INT64_MAX);
    vector<long long> mv(n, -1);
    for (long long i = 0; i < n; ++i) {
        a.insert({INT64_MAX, i});
    }
    vector<bool> used(n, false);
    for (long long i = 0; i < m; ++i) {
        cin >> v >> u >> w;
        v--;
        u--;
        G[v].push_back({u, -w});
        G[u].push_back({v, -w});
        edges.push_back({v, u});
    }
    add(0, used, G, mx, mv, a);
    for (long long i = 1; i < n; ++i) {
        u = a.begin() -> second;
        add(u, used, G, mx, mv, a);
        res.push_back({mv[u], u});
    }
}
