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
    long long n, m, v, u, w, s;
    cin >> n >> m >> s;
    vector <int> res;
    map <pair <long long, long long>, int> edges;
    set <pair <long long, int>> res_edges;
    vector<vector<pair<long long, long long>>> G(n, vector<pair<long long, long long>> ());
    set <pair <long long, long long>> a;
    vector<long long> mx(n, INT64_MAX);
    vector<long long> mv(n, -1);
    for (long long i = 0; i < n; ++i) {
        a.insert({INT64_MAX, i});
    }
    vector<bool> used(n, false);
    for (int i = 0; i < m; ++i) {
        cin >> v >> u >> w;
        v--;
        u--;
        G[v].push_back({u, -w});
        G[u].push_back({v, -w});
        edges[{v, u}] = i;
        edges[{u, v}] = i;
        res_edges.insert({-w, i});
    }
    add(0, used, G, mx, mv, a);
    for (long long i = 1; i < n; ++i) {
        u = a.begin() -> second;
        add(u, used, G, mx, mv, a);
        res_edges.erase({mx[u], edges[{mv[u], u}]});
    }
    while (s >= 0 && !res_edges.empty()) {
        s += prev(res_edges.end()) -> first;
        if (s >= 0) {
            res.push_back(prev(res_edges.end()) -> second);
            res_edges.erase(prev(res_edges.end()));
        }
    }
    cout << res.size() << "\n";
    for (int i : res) {
        cout << i + 1 << " ";
    }
}
