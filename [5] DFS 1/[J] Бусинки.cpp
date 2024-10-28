#include <bits/stdc++.h>

using namespace std;

void dfs(long long vershina, vector <long long> &used, vector <vector <long long>> &G, long long n) {
    used[vershina] = n;
    for (long long i : G[vershina]) {
        if (used[i] == 0) {
            dfs(i, used, G, n + 1);
        } else {
            used[i] = min(used[i], n + 1);
        }
    }
}

int main() {
    long long n, a_v, b_v;
    cin >> n;
    vector<vector<long long>> G(n, vector<long long>());
    for (long long i = 0; i < n - 1; i++) {
        cin >> a_v >> b_v;
        G[a_v - 1].push_back(b_v - 1);
        G[b_v - 1].push_back(a_v - 1);
    }
    vector<long long> used(n, 0);
    dfs(0, used, G, 1);
    long long max_v_n = 1, max_v;
    for (long long i : used) {
        max_v_n = max(i, max_v_n);
    }
    for (long long i = 0; i < n; ++i) {
        if (used[i] == max_v_n) {
            max_v = i;
        }
    }
    used = vector<long long>(n, 0);
    dfs(max_v, used, G, 1);
    max_v_n = 0;
    for (long long i : used) {
        max_v_n = max(i, max_v_n);
    }
    cout << max_v_n;
}
