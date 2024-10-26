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
    long long n, s, dop, res = 0;
    cin >> n >> s;
    vector <vector <long long>> g(n, vector <long long> ());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dop;
            if (dop) {
                g[i].push_back(j);
            }
        }
    }
    vector <long long> used(n, 0);
    dfs(s - 1, used, g, 1);
    for (int i = 0; i < n; ++i) {
        res += used[i];
    }
    cout << res;
}
