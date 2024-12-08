#include <bits/stdc++.h>

using namespace std;

void dfs_t(int v, vector <vector <int>> &G, vector <int> &t_out, vector <bool> &used) {
    used[v] = true;
    for (int u : G[v]) {
        if (!used[u]) {
            dfs_t(u, G, t_out, used);
        }
    }
    t_out.push_back(v);
}

void dfs(int v, int color, vector <int> &component, vector <vector <int>> &G_obr) {
    component[v] = color;
    for (int u : G_obr[v]) {
        if (component[u] == -1) {
            dfs(u, color, component, G_obr);
        }
    }
}

int main() {
    int n, m, u, v, color = 1;
    cin >> n >> m;
    vector <vector <int>> A(n + 2, vector <int> (m + 2, INT32_MAX));
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= m; ++j) {
            cin >> A[i][j];
        }
    }
    vector <vector <int>> G(n * m, vector <int> ());
    vector <vector <int>> G_obr(n * m, vector <int> ());
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= m; ++j) {
            if (A[i][j - 1] != INT32_MAX && A[i][j] >= A[i][j - 1]) {
                G[(i - 1) * m + j - 1].push_back((i - 1) * m + j - 2);
            }
            if (A[i][j - 1] != INT32_MAX && A[i][j] <= A[i][j - 1]) {
                G_obr[(i - 1) * m + j - 1].push_back((i - 1) * m + j - 2);
            }
            if (A[i][j + 1] != INT32_MAX && A[i][j] >= A[i][j + 1]) {
                G[(i - 1) * m + j - 1].push_back((i - 1) * m + j);
            }
            if (A[i][j + 1] != INT32_MAX && A[i][j] <= A[i][j + 1]) {
                G_obr[(i - 1) * m + j - 1].push_back((i - 1) * m + j);
            }
            if (A[i - 1][j] != INT32_MAX && A[i][j] >= A[i - 1][j]) {
                G[(i - 1) * m + j - 1].push_back((i - 2) * m + j - 1);
            }
            if (A[i - 1][j] != INT32_MAX && A[i][j] <= A[i - 1][j]) {
                G_obr[(i - 1) * m + j - 1].push_back((i - 2) * m + j - 1);
            }
            if (A[i + 1][j] != INT32_MAX && A[i][j] >= A[i + 1][j]) {
                G[(i - 1) * m + j - 1].push_back(i * m + j - 1);
            }
            if (A[i + 1][j] != INT32_MAX && A[i][j] <= A[i + 1][j]) {
                G_obr[(i - 1) * m + j - 1].push_back(i * m + j - 1);
            }
        }
    }
    /*
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= m; ++j) {
            cout << i << " " << j << ": ";
            for (long long c : G_obr[(i - 1) * m + j - 1]) {
                cout << c << " ";
            }
            cout << "\n";
        }
    }
    return 0;
    */
    vector <int> t_out;
    vector <int> component(n * m, -1);
    vector <bool> used(n * m, false);
    for (int i = 0; i < n * m; ++i) {
        if (!used[i]) {
            dfs_t(i, G, t_out, used);
        }
    }
    reverse(t_out.begin(), t_out.end());
    for (int i : t_out) {
        if (component[i] == -1) {
            dfs(i, color, component, G_obr);
            color++;
        }
    }
    vector <vector <long long>> edges(color, vector <long long> ());
    for (int v = 0; v < n * m; ++v) {
        for (int u : G[v]) {
            if (component[v] != component[u]) {
                edges[component[v]].push_back(component[u]);
            }
        }
    }
    long long res = 0;
    for (vector <long long> i : edges) {
        if (i.empty()) {
            res++;
        }
    }
    cout << res - 1;
}
