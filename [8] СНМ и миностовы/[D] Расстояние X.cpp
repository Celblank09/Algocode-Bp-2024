#include <bits/stdc++.h>

using namespace std;

int get(int v, vector <int> &pred) {
    if (pred[v] == -1) {
        pred[v] = v;
    }
    if (pred[v] == v) {
        return v;
    }
    pred[v] = get(pred[v], pred);
    return pred[v];
}

void unite(int u, int v, vector <int> &sz, vector <int> &pred) {
    u = get(u, pred);
    v = get(v, pred);
    if (u == v) {
        return;
    }
    if (sz[u] > sz[v]) {
        swap(u, v);
    }
    pred[u] = v;
    sz[v] += sz[u];
}

int main() {
    int n, m, x, b, e, w;
    set <int> component;
    long long res = 0;
    cin >> n >> m >> x;
    vector <int> pred(n, -1);
    vector <int> sz(n, 1);
    vector<pair<int, int>> edges_b;
    for (int i = 0; i < m; ++i) {
        cin >> b >> e >> w;
        b--;
        e--;
        if (w < x) {
            edges_b.push_back({b, e});
        }
        if (w <= x) {
            unite(b, e, sz, pred);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!component.count(get(i, pred))) {
            component.insert(get(i, pred));
            res += (sz[get(i, pred)] * (sz[get(i, pred)] - 1)) / 2;
        }
    }
    pred = vector <int>(n, -1);
    sz = vector <int>(n, 1);
    component.clear();
    for (auto i : edges_b) {
        unite(i.first, i.second, sz, pred);
    }
    for (int i = 0; i < n; ++i) {
        if (!component.count(get(i, pred))) {
            component.insert(get(i, pred));
            res -= (sz[get(i, pred)] * (sz[get(i, pred)] - 1)) / 2;
        }
    }
    cout << res;
}
