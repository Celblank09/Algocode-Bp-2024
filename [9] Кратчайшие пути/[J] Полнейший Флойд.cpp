#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, b, e, w;
    cin >> n >> m;
    vector <vector <long long>> d(n, vector <long long> (n, INT32_MAX));
    vector <vector <long long>> next(n, vector <long long> (n, -1));
    for (long long i = 0; i < n; ++i) {
        d[i][i] = 0;
        next[i][i] = i;
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
                if (d[u][i] + d[i][v] < d[u][v] && d[u][i] != INT32_MAX && d[i][v] != INT32_MAX) {
                    d[u][v] = max(d[u][i] + d[i][v], (long long)INT32_MIN);
                    next[u][v] = next[u][i];
                }
            }
            for (long long t = 0; t < n; ++t) {
                if (d[t][t] < 0) {
                    cout << "LOOP\n";
                    vector <long long> res;
                    res.push_back(t + 1);
                    long long y = next[t][t];
                    while (y != t) {
                        res.push_back(y + 1);
                        y = next[y][t];
                    }
                    cout << res.size() << "\n";
                    for (long long y : res) {
                        cout << y << " ";
                    }
                    return 0;
                }
            }
        }
    }
    for (long long i = 0; i < n; ++i) {
        if (d[i][i] < 0) {
            cout << "LOOP\n";
            vector <long long> res;
            res.push_back(i + 1);
            long long u = next[i][i];
            while (u != i) {
                res.push_back(u + 1);
                u = next[u][i];
            }
            cout << res.size() << "\n";
            for (long long v : res) {
                cout << v << " ";
            }
            return 0;
        }
    }
    cout << "NO LOOP\n";
    for (long long u = 0; u < n; ++u) {
        for (long long v = 0; v < n; ++v) {
            if (d[u][v] == INT32_MAX) {
                cout << "INF ";
            } else {
                cout << d[u][v] << " ";
            }
        }
        cout << "\n";
    }
}
