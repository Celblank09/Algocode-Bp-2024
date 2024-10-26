#include <bits/stdc++.h>

using namespace std;

bool dfs(long long vershina, vector <long long> &used, vector <vector <long long>> &g) {
    used[vershina] = 1;
    bool res = false;
    for (long long i : g[vershina]) {
        if (used[i] == 0) {
            if (dfs(i, used, g)) {
                res = true;
            }
        } else if (used[i] == 1) {
            res = true;
        }
    }
    used[vershina] = 2;
    return res;
}

int main() {
    long long n, m, a_v, b_v, flag = true;
    cin >> n >> m;
    vector <vector <long long>> g(n, vector <long long> ());
    for (int i = 0; i < m; ++i) {
        cin >> a_v >> b_v;
        g[a_v - 1].push_back(b_v - 1);
    }
    vector <long long> used(n, 0);
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            if (dfs(i, used, g)) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
}
