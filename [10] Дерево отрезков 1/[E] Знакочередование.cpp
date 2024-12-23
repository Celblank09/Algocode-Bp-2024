#include <bits/stdc++.h>

using namespace std;

void BUILD(int v, int l, int r, vector <long long> &t, vector <long long> &a) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    BUILD(2 * v, l, mid, t, a);
    BUILD(2 * v + 1, mid, r, t, a);
    t[v] = t[2 * v] + t[2 * v + 1];
}

void SET(int v, int l, int r, int ind, long long x, vector <long long> &t) {
    if (l + 1 == r) {
        t[v] = x;
        return;
    }
    int mid = (l + r) / 2;
    if (ind < mid) {
        SET(2 * v, l, mid, ind, x, t);
    } else {
        SET(2 * v + 1, mid, r, ind, x, t);
    }
    t[v] = t[2 * v] + t[2 * v + 1];
}

long long GET(int v, int vl, int vr, int ql, int qr, vector <long long> &t) {
    if (vl >= qr || vr <= ql) {
        return 0;
    }
    if (vl >= ql && vr <= qr) {
        return t[v];
    }
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t);
    return res1 + res2;
}

int main() {
    int n;
    cin >> n;
    vector <long long> t1(4 * n, 0);
    vector <long long> t2(4 * n, 0);
    vector <long long> a1(n, 0);
    vector <long long> a2(n, 0);
    for (int j = 0; j < n; ++j) {
        if (j % 2 == 0) {
            cin >> a1[j];
        } else {
            cin >> a2[j];
        }
    }
    BUILD(1, 0, n, t1, a1);
    BUILD(1, 0, n, t2, a2);
    int m, l, r;
    string type;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> type >> l >> r;
        if (type == "1") {
            if (l % 2 == 1) {
                cout << GET(1, 0, n, l - 1, r, t1) -
                        GET(1, 0, n, l - 1, r, t2) << "\n";
            } else {
                cout << GET(1, 0, n, l - 1, r, t2) -
                        GET(1, 0, n, l - 1, r, t1) << "\n";
            }
        } else {
            if (l % 2 == 1) {
                SET(1, 0, n, l - 1, r, t1);
            } else {
                SET(1, 0, n, l - 1, r, t2);
            }
        }
    }
}
