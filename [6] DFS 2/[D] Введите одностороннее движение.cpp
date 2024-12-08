#include <bits/stdc++.h>

using namespace std;

void dfs(long long v, long long p, vector<vector<long long>> &G, vector<bool> &used, vector<long long> &h,
         vector<long long> &upH,
         vector<pair<long long, long long>> &most) {
    used[v] = true;
    upH[v] = h[v];
    for (long long u : G[v]) {
        if (u == p) {
            continue;
        } else if (used[u]) {
            upH[v] = min(h[u], upH[v]);
        } else {
            h[u] = h[v] + 1;
            dfs(u, v, G, used, h, upH, most);
            upH[v] = min(upH[u], upH[v]);
            if (upH[u] > h[v]) {
                most.push_back({v, u});
            }
        }
    }
}

void dfs_res(long long v, vector<vector<long long>> &G, vector<bool> &used,
             map<pair<long long, long long>, long long> &rebra, vector<pair<long long, long long>> &res) {
    used[v] = true;
    for (long long u : G[v]) {
        res[rebra[{v, u}]] = {v, u};
        if (used[u]) {
            continue;
        }
        dfs_res(u, G, used, rebra, res);
    }
}

int main() {
    long long n, m, u, v;
    cin >> n >> m;
    vector<vector<long long>> G(n, vector<long long>());
    vector<bool> used(n, false);
    vector<long long> h(n, 0);
    vector<long long> upH(n, 0);
    vector<pair<long long, long long>> most;
    vector<pair<long long, long long>> res(m + 1, pair<long long, long long> {0, 0});
    map<pair<long long, long long>, long long> rebra;
    map<pair<long long, long long>, vector <long long>> rebra_c;
    for (long long i = 1; i <= m; ++i) {
        cin >> u >> v;
        u--;
        v--;
        if (!rebra[{v, u}]) {
            G[u].push_back(v);
            G[v].push_back(u);
        }
        rebra[{u, v}] = i;
        rebra[{v, u}] = i;
        rebra_c[{u, v}].push_back(i);
        rebra_c[{v, u}].push_back(i);
    }
    for (long long i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, i, G, used, h, upH, most);
        }
    }
    for (auto i : most) {
        if (rebra_c[i].size() == 1) {
            cout << 0;
            return 0;
        }
    }
    used = vector<bool> (n, false);
    dfs_res(0, G, used, rebra, res);
    for (auto i : rebra) {
        if (rebra_c[i.first].size() > 1) {
            res[rebra_c[i.first][0]] = {i.first.second, i.first.first};
            for (long long j = 1; j < rebra_c[i.first].size(); ++j) {
                res[rebra_c[i.first][j]] = {i.first.first, i.first.second};
            }
        }
    }
    for (long long i = 1; i <= m; ++i) {
        cout << res[i].first + 1 << " " << res[i].second + 1 << "\n";
    }
}
