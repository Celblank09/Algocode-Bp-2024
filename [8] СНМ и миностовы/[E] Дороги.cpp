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

long long d(int v, int u, vector<pair<long long, long long>> &cities) {
    long long dx = cities[u].first - cities[v].first;
    long long dy = cities[u].second - cities[v].second;
    return dx * dx + dy * dy;
}

void add(int v, vector<long long> &mx, long long n, vector<pair<long long, long long>> &cities, vector <int> &pred) {
    for (int i = 0; i < n; ++i) {
        if (mx[i] > d(v, i, cities) && get(v, pred) != get(i, pred)) {
            mx[i] = d(v, i, cities);
        }
    }
}

int main() {
    int n, b, m, v, u;
    double res = 0;
    cin >> n;
    vector<long long> mx(n, INT64_MAX);
    vector <int> pred(n, -1);
    vector <int> sz(n, 1);
    vector<pair<long long, long long>> cities(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> v >> u;
        unite(v - 1, u - 1, sz, pred);
    }
    for (int k = 0; k < n; ++k) {
        if (get(k, pred) == get(0, pred)) {
            add(k, mx, n, cities, pred);
        }
    }
    for (int i = 1; i < n; ++i) {
        u = -1;
        for (int k = 1; k < n; ++k) {
            if (get(0, pred) != get(k, pred) && (u == -1 || mx[k] < mx[u])) {
                u = k;
            }
        }
        if (u == -1) {
            break;
        }
        unite(0, u, sz, pred);
        for (int k = 0; k < n; ++k) {
            if (get(k, pred) == get(0, pred)) {
                add(k, mx, n, cities, pred);
            }
        }
        res += sqrt(mx[u]);
    }
    cout << fixed << setprecision(10);
    cout << res;
}
