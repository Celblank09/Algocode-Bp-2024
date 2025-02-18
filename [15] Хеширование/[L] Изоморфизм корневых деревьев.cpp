#include <bits/stdc++.h>

using namespace std;

mt19937 rng(120);

long long dfs(int u, vector <vector <int>> &G, vector <bool> &used, map <vector <long long>, long long> &eq,
              vector <long long> &hashes) {
    used[u] = 1;
    vector <long long> p_h;
    for (int v : G[u]) {
        if (!used[v]) {
            p_h.push_back(dfs(v, G, used, eq, hashes));
        }
    }
    sort(p_h.begin(), p_h.end());
    if (!eq[p_h]) {
        eq[p_h] = rng();
    }
    hashes[u] = eq[p_h];
    return hashes[u];
}

int main() {
    int n, r1, r2, u, v;
    cin >> n;
    vector <vector <int>> G1(n + 1, vector <int> ()), G2(n + 1, vector <int> ());
    vector <bool> used1(n + 1, 0), used2(n + 1, 0);
    map <vector <long long>, long long> eq;
    vector <long long> hashes1(n + 1, 0), hashes2(n + 1, 0);
    cin >> r1 >> r2;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }
    if (dfs(r1, G1, used1, eq, hashes1) == dfs(r2, G2, used2, eq, hashes2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}