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
    long long n, m, u, v;
    cin >> n >> m;
    vector<vector<long long>> G(n, vector<long long>());
    vector <long long> res;
    vector<bool> used(n, false);
    vector<long long> h(n, 0);
    vector<long long> upH(n, 0);
    vector<bool> cutpoints(n, false);
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
            dfs(i, i, G, used, h, upH, cutpoints);
        }
    }
    cout << count(cutpoints.begin(), cutpoints.end(), true) << "\n";
    for (long long i = 0; i < n; ++i) {
        if (cutpoints[i]) {
            cout << i + 1 << " ";
        }
    }
}
