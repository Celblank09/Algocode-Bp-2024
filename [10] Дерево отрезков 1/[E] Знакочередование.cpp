#include <bits/stdc++.h>

using namespace std;

void BUILD(int v, int l, int r, vector <long long> &t, vector <long long> &i, vector <long long> &a) {
    if (l + 1 == r) {
        t[v] = a[l];
        i[v] = l;
        return;
    }
    int mid = (l + r) / 2;
    BUILD(2 * v, l, mid, t, i, a);
    BUILD(2 * v + 1, mid, r, t, i, a);
    if (t[2 * v] > t[2 * v + 1]) {
        t[v] = t[2 * v];
        i[v] = i[2 * v];
    } else {
        t[v] = t[2 * v + 1];
        i[v] = i[2 * v + 1];
    }
}

int GET(int v, int vl, int vr, int ql, int qr, vector <long long> &t,
        vector <long long> &i, vector <long long> &a) {
    if (vl >= qr || vr <= ql) {
        return -1;
    }
    if (vl >= ql && vr <= qr) {
        return i[v];
    }
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t, i, a);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t, i, a);
    if (res2 == -1 || (res1 != -1 && a[res1] > a[res2])) {
        return res1;
    } else {
        return res2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <long long> t(4 * n, 0);
    vector <long long> i(4 * n, 0);
    vector <long long> a(n, 0);
    for (int j = 0; j < n; ++j) {
        cin >> a[j];
    }
    BUILD(1, 0, n, t, i, a);
    int m, l, r;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> l >> r;
        auto res = GET(1, 0, n, l - 1, r, t, i, a);
        cout << res + 1 << "\n";
    }
}
