#include <bits/stdc++.h>

using namespace std;

void dfs(long long v, long long p, vector<vector<long long>> &G, vector<long long> &used, vector <long long> &h, vector<long long> &upH,
         set<pair<long long, long long>> &most) {
    used[v] = 1;
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
                most.insert({v, u});
            }
        }
    }
}

void dfs_diam(long long v, vector<vector<long long>> &G, vector<long long> &used, set<pair<long long, long long>> &most, long long cur) {
    used[v] = cur;
    for (long long u : G[v]) {
        if (!used[u]) {
            if (most.count({v, u}) || most.count({u, v})) {
                dfs_diam(u, G, used, most, cur + 1);
            } else {
                dfs_diam(u, G, used, most, cur);
            }
        }
    }
}

void dfs_component(long long v, vector<vector<long long>> &G, vector<long long> &component, long long cur) {
    component[v] = cur;
    for (long long u : G[v]) {
        if (!component[u]) {
            dfs_component(u, G, component, cur);
        }
    }
}

int main() {
    long long n, m, u, v, cur = 1;
    cin >> n >> m;
    vector<vector<long long>> G(n, vector<long long>());
    vector<long long> used(n, 0);
    vector<long long> h(n, 0);
    vector<long long> upH(n, 0);
    vector<long long> component(n, 0);
    set<pair<long long, long long>> most;
    for (long long i = 1; i <= m; ++i) {
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (long long i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, i, G, used, h, upH, most);
        }
    }
    long long res = 0;
    for (long long i = 0; i < n; ++i) {
        if (!component[i]) {
            dfs_component(i, G, component, cur);
            cur++;
        }
    }
    cur = 1;
    long long x;
    for (long long i = 0; i < n; ++i) {
        if (component[i] == cur) {
            dfs_diam(i, G, used, most, 1);
            cur++;
            x = i;
            for (long long j = 0; j < n; ++j) {
                if (component[j] == component[i] && used[j] > used[x]) {
                    x = j;
                }
            }
            used = vector<long long> (n, 0);
            dfs_diam(x, G, used, most, 1);
            long long y = i;
            for (long long j = 0; j < n; ++j) {
                if (component[j] == component[i] && used[j] > used[y]) {
                    y = j;
                }
            }
            if (used[y] > 2) {
                res = max(res, used[y] - 1);
            } else if (used[y] == 2) {
                for (long long j : G[x]) {
                    if (!most.count({j, x}) && !most.count({x, j})) {
                        res = max(res, (long long)1);
                        break;
                    }
                }
                for (long long j : G[y]) {
                    if (!most.count({j, y}) && !most.count({y, j})) {
                        res = max(res, (long long)1);
                        break;
                    }
                }
            }
        }
    }
    cout << most.size() - res;
}
