#include <bits/stdc++.h>

using namespace std;

void add(int v, vector<bool> &used, vector<vector<pair<long long, long long>>> &G, vector<long long> &mx,
         set <pair <long long, int>> &a) {
    used[v] = true;
    a.erase({mx[v], v});
    for (auto i : G[v]) {
        if (used[i.first]) {
            continue;
        }
        if (mx[i.first] > i.second) {
            a.erase({mx[i.first], i.first});
            mx[i.first] = i.second;
            a.insert({mx[i.first], i.first});
        }
    }
}

int main() {
    long long n, m, b, e, w, res = 0, min_v = 0;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> G(n, vector<pair<long long, long long>> ());
    vector<long long> mx(n, INT64_MAX);
    vector<long long> point(n, -1);
    vector<bool> used(n, false);
    set <pair <long long, int>> a;
    for (long long i = 0; i < n; ++i) {
        a.insert({INT64_MAX, i});
        cin >> point[i];
        if (point[i] < point[min_v]) {
            min_v = i;
        }
    }
    for (long long i = 0; i < n; ++i) {
        if (i != min_v) {
            G[i].push_back({min_v, point[min_v] + point[i]});
            G[min_v].push_back({i, point[min_v] + point[i]});
        }
    }
    for (long long i = 0; i < m; ++i) {
        cin >> b >> e >> w;
        b--;
        e--;
        G[b].push_back({e, w});
        G[e].push_back({b, w});
    }
    add(min_v, used, G, mx, a);
    for (int i = 1; i < n; ++i) {
        int u = a.begin() -> second;
        add(u, used, G, mx, a);
        res += mx[u];
    }
    cout << res;
}
