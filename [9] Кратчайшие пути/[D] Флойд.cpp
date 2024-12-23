#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, b, e, w;
    cin >> n >> m;
    vector <vector <long long>> d(n, vector <long long> (n, INT64_MAX));
    vector <vector <long long>> next(n, vector <long long> (n, -1));
    for (long long i = 0; i < n; ++i) {
        d[i][i] = 0;
    }
    for (long long i = 0; i < m; ++i) {
        cin >> b >> e >> w;
        b--;
        e--;
        d[b][e] = min(w, d[b][e]);
        next[b][e] = e;
    }
    for (long long i = 0; i < n; ++i) {
        for (long long u = 0; u < n; ++u) {
            for (long long v = 0; v < n; ++v) {
                if (d[u][i] != INT64_MAX && d[i][v] != INT64_MAX && d[u][i] + d[i][v] < d[u][v]) {
                    d[u][v] = d[u][i] + d[i][v];
                    next[u][v] = next[u][i];
                }
            }
        }
    }
    for (long long u = 0; u < n; ++u) {
        for (long long v = 0; v < n; ++v) {
            cout << min(d[u][v], (long long)30000) << " ";
        }
        cout << "\n";
    }
}
