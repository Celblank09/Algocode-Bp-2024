#include <bits/stdc++.h>

using namespace std;

void dfs(long long v, long long p, vector<vector<long long>> &G, vector<bool> &used, vector <long long> &h, vector<long long> &upH,
         vector<bool> &cutpoints) {
    long long ch = 0;
    used[v] = true;
    upH[v] = h[v];
    for (long long u : G[v]) {
        if (u == p) {
            continue;
        } else if (used[u]) {
            upH[v] = min(h[u], upH[v]);
        } else {
            h[u] = h[v] + 1;
            dfs(u, v, G, used, h, upH, cutpoints);
            ch++;
            upH[v] = min(upH[u], upH[v]);
            if (upH[u] >= h[v] && h[v] != 0) {
                cutpoints[v] = true;
            }
        }
    }
    if (h[v] == 0 && ch > 1) {
        cutpoints[v] = true;
    }
}

int main() {
    long long n, m, u, v, k;
    cin >> n >> m;
    vector<vector<long long>> G(n + m, vector<long long>());
    vector<bool> used(n + m, false);
    vector<long long> h(n + m, 0);
    vector<long long> upH(n + m, 0);
    vector<bool> cutpoints(n + m, false);
    for (long long i = 1; i <= m; ++i) {
        cin >> u >> v >> k;
        u--;
        v--;
        k--;
        G[u + m].push_back(i - 1);
        G[i - 1].push_back(u + m);
        G[v + m].push_back(i - 1);
        G[i - 1].push_back(v + m);
        G[k + m].push_back(i - 1);
        G[i - 1].push_back(k + m);
    }
    dfs(0, 0, G, used, h, upH, cutpoints);
    long long res_c = 0;
    for (long long i = 0; i < m; ++i) {
        if (cutpoints[i]) {
            res_c++;
        }
    }
    cout << res_c << "\n";
    for (long long i = 0; i < m; ++i) {
        if (cutpoints[i]) {
            cout << i + 1 << "\n";
        }
    }
}
