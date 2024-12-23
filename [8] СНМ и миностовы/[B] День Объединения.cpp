#include <bits/stdc++.h>

using namespace std;

void add(int v, vector<bool> &used, vector<vector<long long>> &G, vector<long long> &mx,
         vector<int> &mv, set<pair<long long, int>> &a, long long n) {
    used[v] = true;
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        if (mx[i] > G[v][i]) {
            mx[i] = G[v][i];
            mv[i] = v;
        }
    }
}

vector<vector<long long>> G(5000, vector<long long>(5000, INT64_MAX));

int main() {
    int n, b;
    long long x, y;
    double res = 0;
    cin >> n;
    set<pair<long long, int>> a;
    vector<long long> mx(n, INT64_MAX);
    vector<int> mv(n, -1);
    vector<pair<long long, long long>> cities;
    for (int i = 0; i < n; ++i) {
        a.insert({INT64_MAX, i});
    }
    vector<bool> used(n, false);
    for (int v = 0; v < n; ++v) {
        cin >> x >> y;
        cities.push_back({x, y});
    }
    for (int v = 0; v < n; ++v) {
        for (int u = 0; u < n; ++u) {
            long long dx = cities[v].first - cities[u].first;
            long long dy = cities[v].second - cities[u].second;
            G[v][u] = dx * dx + dy * dy;
        }
    }
    add(0, used, G, mx, mv, a, n);
    for (int i = 1; i < n; ++i) {
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (!used[v] && (u == -1 || mx[v] < mx[u])) {
                u = v;
            }
        }
        add(u, used, G, mx, mv, a, n);
        res += sqrt(mx[u]);
    }
    cout << fixed << setprecision(10);
    cout << res;
}
