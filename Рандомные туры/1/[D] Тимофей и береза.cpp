#include <bits/stdc++.h>

using namespace std;

void dfs(int v, int root, vector <vector <int>> &G, vector <int> &colors, vector <int> &used) {
    if (v == root) {
        used[v] = colors[v];
    }
    for (int u : G[v]) {
        if (used[u] == 0) {
            if (v == root) {
                used[u] = colors[u];
            } else {
                used[u] = colors[v];
            }
            dfs(u, root, G, colors, used);
        }
    }
}

int main() {
    int n, u, v;
    bool flag = false;
    cin >> n;
    vector <vector <int>> G(n, vector <int> ());
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector <int> colors(n, 0);
    vector <int> used(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j : G[i]) {
            if (colors[i] != colors[j]) {
                u = i;
                v = j;
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    if (!flag) {
        cout << "YES\n1";
        return 0;
    }
    dfs(u, u, G, colors, used);
    flag = true;
    for (int i = 0; i < n; ++i) {
        if (colors[i] != used[i]) {
            flag = false;
        }
    }
    if (flag) {
        cout << "YES\n" << u + 1;
        return 0;
    }
    used = vector <int> (n, 0);
    dfs(v, v, G, colors, used);
    flag = true;
    for (int i = 0; i < n; ++i) {
        if (colors[i] != used[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n" << v + 1;
}