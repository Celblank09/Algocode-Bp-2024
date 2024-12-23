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

void unite(int u, int v, vector <int> &sz,  vector <long long> &sum, vector <int> &pred) {
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
    sum[v] += sum[u];
}

int main() {
    int n;
    long long res = 0;
    cin >> n;
    vector <long long> a(n, 0);
    vector <int> sz(n, 0);
    vector <int> pred(n, -1);
    vector <long long> sum(n, 0);
    vector <long long> b(n, 0);
    vector <long long> ans;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i]--;
    }
    reverse(b.begin(), b.end());
    for (int i : b) {
        ans.push_back(res);
        sum[i] += a[i];
        sz[i]++;
        if (i != 0 && pred[i - 1] != -1) {
            unite(i, i - 1, sz, sum, pred);
        }
        if (i != n - 1 && pred[i + 1] != -1) {
            unite(i, i + 1, sz, sum, pred);
        }
        res = max(res, sum[get(i, pred)]);
    }
    reverse(ans.begin(), ans.end());
    for (long long i : ans) {
        cout << i << "\n";
    }
}
