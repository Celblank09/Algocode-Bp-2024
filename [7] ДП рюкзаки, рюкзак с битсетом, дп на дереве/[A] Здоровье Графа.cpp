#include <bits/stdc++.h>

using namespace std;

void dfs(vector<long long> &used, vector<pair<long long, long long>> &dp, vector<vector<long long>> &G, long long v,
         long long pred, long long start) {
    dp[v] = {1, start};
    used[v] = 1;
    for (long long u : G[v]) {
        if (u != pred) {
            dfs(used, dp, G, u, v, start);
            dp[v].first += dp[u].first;
        }
    }
}

int main() {
    long long n, m, q, e;
    cin >> n >> m;
    vector<vector<long long>> G(n, vector<long long>());
    vector<pair<long long, long long>> dp(n, {0, 0});
    vector<long long> used(n, 0);
    vector<pair<long long, long long>> E(m, pair<long long, long long>());
    for (long long i = 0; i < m; ++i) {
        cin >> E[i].first >> E[i].second;
        E[i].first--;
        E[i].second--;
        G[E[i].first].push_back(E[i].second);
        G[E[i].second].push_back(E[i].first);
    }
    for (long long i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(used, dp, G, i, -1, i);
        }
    }
    cin >> q;
    for (long long i = 0; i < q; ++i) {
        cin >> e;
        e--;
        cout << min(dp[E[e].first].first, dp[E[e].second].first) *
                (dp[dp[E[e].first].second].first - min(dp[E[e].first].first, dp[E[e].second].first));
        cout << "\n";
    }
}
