#include <bits/stdc++.h>

using namespace std;

bool dfs(long long vershina, vector <long long> &used, vector <vector <long long>> &g, long long n) {
    bool res = true;
    used[vershina] = 1 - n;
    for (long long i : g[vershina]) {
        if (used[i] == -1) {
            if (!dfs(i, used, g, 1 - n)) {
                res = false;
            }
        } else if (used[i] == used[vershina]) {
            res = false;
        }
    }
    return res;
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
    vector <long long> used(n, -1);
    for (int i = 0; i < n; ++i) {
        if (used[i] == -1) {
            if (!dfs(i, used, g, 0)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
