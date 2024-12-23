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

void SET(int v, int l, int r, int ind, long long x, vector <long long> &t, vector <long long> &i) {
    if (l + 1 == r) {
        t[v] = x;
        i[v] = l;
        return;
    }
    int mid = (l + r) / 2;
    if (ind < mid) {
        SET(2 * v, l, mid, ind, x, t, i);
    } else {
        SET(2 * v + 1, mid, r, ind, x, t, i);
    }
    if (t[2 * v] > t[2 * v + 1]) {
        t[v] = t[2 * v];
        i[v] = i[2 * v];
    } else {
        t[v] = t[2 * v + 1];
        i[v] = i[2 * v + 1];
    }
}

pair <long long, int> GET(int v, int vl, int vr, int ql, int qr, vector <long long> &t,
                          vector <long long> &i) {
    if (vl >= qr || vr <= ql) {
        return {INT64_MIN, 0};
    }
    if (vl >= ql && vr <= qr) {
        return {t[v], i[v]};
    }
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t, i);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t, i);
    if (res1.first > res2.first) {
        return res1;
    } else {
        return res2;
    }
}

int main() {
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
        auto res = GET(1, 0, n, l - 1, r, t, i);
        cout << res.first << " " << res.second + 1 << "\n";
    }
}
