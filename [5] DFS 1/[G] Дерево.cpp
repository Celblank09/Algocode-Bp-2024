#include <bits/stdc++.h>

using namespace std;

void dfs(long long vershina, vector <long long> &used, vector <vector <long long>> &g, long long n) {
    used[vershina] = n;
    for (long long i : g[vershina]) {
        if (used[i] == 0) {
            dfs(i, used, g, n);
        }
    }
}

int main() {
    long long n, m, a_v, b_v, flag = true;
    cin >> n >> m;
    vector <vector <long long>> g(n, vector <long long> ());
    for (int i = 0; i < m; ++i) {
        cin >> a_v >> b_v;
        g[a_v - 1].push_back(b_v - 1);
        g[b_v - 1].push_back(a_v - 1);
    }
    vector <long long> used(n, 0);
    dfs(0, used, g, 1);
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            flag = false;
        }
    }
    if (flag && m == n - 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
