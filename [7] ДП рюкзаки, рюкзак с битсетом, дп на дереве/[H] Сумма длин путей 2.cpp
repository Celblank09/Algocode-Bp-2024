#include <bits/stdc++.h>

using namespace std;

void dfs_sz(long long v, vector<bool> &used, vector<vector<pair<long long, long long>>> &G, vector<long long> &sz) {
    used[v] = true;
    for (auto u : G[v]) {
        if (!used[u.first]) {
            dfs_sz(u.first, used, G, sz);
            sz[v] += sz[u.first];
        }
    }
    sz[v]++;
}

void dfs_dp(long long v, vector<bool> &used, vector<vector<pair<long long, long long>>> &G, vector<long long> &sz,
            vector<long long> &dp) {
    used[v] = true;
    for (auto u : G[v]) {
        if (!used[u.first]) {
            dfs_dp(u.first, used, G, sz, dp);
            dp[v] += dp[u.first] + u.second * sz[u.first];
        }
    }
}

void dfs_sum(long long v, vector<bool> &used, vector<vector<pair<long long, long long>>> &G, vector<long long> &sz,
             vector<long long> &sum) {
    used[v] = true;
    for (auto u : G[v]) {
        if (!used[u.first]) {
            sum[u.first] = sum[v] + (used.size() - 2 * sz[u.first]) * u.second;
            dfs_sum(u.first, used, G, sz, sum);
        }
    }
}

int main() {
    long long n, v, u, w;
    cin >> n;
    vector<vector<pair<long long, long long>>> G(n, vector<pair<long long, long long>>());
    vector<bool> used(n, false);
    vector<long long> sz(n, 0);
    vector<long long> dp(n, 0);
    vector<long long> sum(n, 0);
    for (int i = 1; i < n; ++i) {
        cin >> v >> u >> w;
        v--;
        u--;
        G[v].push_back({u, w});
        G[u].push_back({v, w});
    }
    dfs_sz(0, used, G, sz);
    used = vector<bool>(n, false);
    dfs_dp(0, used, G, sz, dp);
    used = vector<bool>(n, false);
    sum[0] = dp[0];
    dfs_sum(0, used, G, sz, sum);
    for (long long i : sum) {
        cout << i << " ";
    }
}
