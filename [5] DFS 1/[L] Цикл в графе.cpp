#include <bits/stdc++.h>

using namespace std;

bool cycle(long long v, long long u, vector <long long> &p) {
    vector <long long> path;
    while (v != u) {
        path.push_back(v);
        v = p[v];
        if (v == -1) {
            return false;
        }
    }
    path.push_back(u);
    if (path.size() % 2 == 1) {
        cout << "YES\n" << path.size() << "\n";
        for (long long i : path) {
            cout << i + 1 << " ";
        }
        return true;
    }
    return false;
}

bool dfs(long long v, long long prev, vector <long long> &used, vector <vector <long long>> &G, vector <long long> &p) {
    used[v] = 1;
    for (long long u : G[v]) {
        if (u != prev) {
            if (used[u] == 0) {
                p[u] = v;
                if (dfs(u, v, used, G, p)) {
                    return true;
                }
            } else {
                if (cycle(v, u, p)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    long long n, m, u, v;
    cin >> n >> m;
    vector <vector <long long>> G(n, vector <long long> ());
    vector <long long> used(n, 0);
    vector <long long> p(n, -1);
    for (long long i = 0; i < m; ++i) {
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }
    for (long long i = 0; i < n; ++i) {
        if (used[i] == 0) {
            if (dfs(i, -1, used, G, p)) {
                return 0;
            }
        }
    }
    cout << "NO";
}
