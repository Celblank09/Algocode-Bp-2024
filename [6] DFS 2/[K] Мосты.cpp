#include <bits/stdc++.h>

using namespace std;

void dfs(long long v, long long p, vector<vector<long long>> &G, vector<bool> &used, vector <long long> &h, vector<long long> &upH,
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

int main() {
    long long n, m, u, v;
    cin >> n >> m;
    vector<vector<long long>> G(n, vector<long long>());
    vector <long long> res;
    vector<bool> used(n, false);
    vector<long long> h(n, 0);
    vector<long long> upH(n, 0);
    vector<pair<long long, long long>> most;
    map<pair<long long, long long>, long long> rebra;
    for (long long i = 1; i <= m; ++i) {
        cin >> u >> v;
        u--;
        v--;
        rebra[{u, v}] = i;
        rebra[{v, u}] = i;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (long long i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, i, G, used, h, upH, most);
        }
    }
    cout << most.size() << "\n";
    for (auto i : most) {
        res.push_back(rebra[i]);
    }
    sort(res.begin(), res.end());
    for (auto i : res) {
        cout << i << "\n";
    }
}
