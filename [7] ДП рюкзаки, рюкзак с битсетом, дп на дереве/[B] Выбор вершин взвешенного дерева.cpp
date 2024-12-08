#include <bits/stdc++.h>

using namespace std;

void dfs(vector <vector <long long>> &dp, vector <vector <long long>> &G, vector <long long> &w, long long v, long long p) {
    long long s = 0;
    for (long long u : G[v]) {
        if (u != p) {
            dfs(dp, G, w, u, v);
            dp[v][0] += max(dp[u][0], dp[u][1]);
            s += dp[u][0];
        }
    }
    dp[v][1] = w[v];
    for (long long u : G[v]) {
        if (u != p) {
            dp[v][1] = max(dp[v][1], w[v] + s);
        }
    }
}

int main() {
    long long n, p, q, root;
    cin >> n;
    vector <vector <long long>> dp(n, vector <long long> (2, 0));
    vector <vector <long long>> G(n, vector <long long> ());
    vector <long long> w(n, 0);
    for (long long i = 0; i < n; ++i) {
        cin >> p >> q;
        p--;
        if (p != -1) {
            G[i].push_back(p);
            G[p].push_back(i);
        } else {
            root = i;
        }
        w[i] = q;
    }
    dfs(dp, G, w, root, -1);
    cout << max(dp[root][0], dp[root][1]) << "\n";
}
