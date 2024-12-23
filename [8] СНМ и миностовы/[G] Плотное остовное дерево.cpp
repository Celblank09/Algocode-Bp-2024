#include <bits/stdc++.h>

using namespace std;

void add(int v, vector<bool> &used, vector<vector<pair<int, int>>> &G, vector<int> &mx,
         set <pair <int, int>> &a, int t) {
    used[v] = true;
    a.erase({mx[v], v});
    for (auto i : G[v]) {
        if (used[i.first]) {
            continue;
        }
        if (mx[i.first] > i.second && i.second >= t) {
            a.erase({mx[i.first], i.first});
            mx[i.first] = i.second;
            a.insert({mx[i.first], i.first});
        }
    }
}

int main() {
    int n, m, v, u, w, res_min, res_max, res = INT32_MAX;
    bool flag = true, flag_p;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n, vector<pair<int, int>> ());
    set <pair <int, int>> a;
    set <int> b;
    vector<int> mx;
    vector<bool> used;
    for (int i = 0; i < m; ++i) {
        cin >> v >> u >> w;
        v--;
        u--;
        G[v].push_back({u, w});
        G[u].push_back({v, w});
        b.insert(w);
    }
    for (auto t : b) {
        res_min = t;
        res_max = 0;
        mx = vector<int>(n, INT32_MAX);
        used = vector<bool>(n, false);
        a.clear();
        for (int i = 0; i < n; ++i) {
            a.insert({INT32_MAX, i});
        }
        add(0, used, G, mx, a, t);
        for (long long i = 1; i < n; ++i) {
            u = a.begin()->second;
            add(u, used, G, mx, a, t);
            res_max = max(res_max, mx[u]);
        }
        flag_p = true;
        for (long long i = 0; i < n; ++i) {
            if (!used[i]) {
                flag_p = false;
            }
        }
        if (flag_p) {
            flag = false;
            res = min(res, res_max - res_min);
        }
    }
    if (flag) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << res;
}
