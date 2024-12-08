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
    vector <vector <int>> G(n, vector <int> ());
    vector <vector <int>> G_obr(n, vector <int> ());
    vector <int> t_out;
    vector <int> component(n, -1);
    vector <bool> used(n, false);
    for (int i = 0; i < m; ++i) {
        cin >> v >> u;
        v--;
        u--;
        G[v].push_back(u);
        G_obr[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
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
    vector <vector <bool>> edges(color, vector <bool> (color, false));
    for (int v = 0; v < n; ++v) {
        for (int u : G[v]) {
            if (component[v] != component[u]) {
                edges[component[v]][component[u]] = true;
            }
        }
    }
    int res = 0;
    for (vector <bool> i : edges) {
        for (bool j : i) {
            res += j;
        }
    }
    cout << res;
}
