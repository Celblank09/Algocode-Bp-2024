#include <bits/stdc++.h>

using namespace std;

void dfs(long long vershina, vector <long long> &used, vector <vector <long long>> &g, long long n, long long t) {
    used[vershina] = n;
    for (long long i : g[vershina]) {
        if (used[i] == 0 && i != t) {
            dfs(i, used, g, n, t);
        }
    }
}

int main() {
    long long n, m, a_v, b_v, t, res = 0, u, v, k;
    cin >> n >> m >> t;
    t--;
    vector <vector <long long>> g(n, vector <long long> ());
    for (int i = 0; i < m; ++i) {
        cin >> a_v >> b_v;
        g[a_v - 1].push_back(b_v - 1);
        g[b_v - 1].push_back(a_v - 1);
    }
    vector <long long> used(n, 0);
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0 && i != t) {
            res++;
            dfs(i, used, g, res, t);
        }
    }
    cin >> k;
    for (long long i = 0; i < k; ++i) {
        cin >> u >> v;
        u--;
        v--;
        if (used[u] == used[v]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
