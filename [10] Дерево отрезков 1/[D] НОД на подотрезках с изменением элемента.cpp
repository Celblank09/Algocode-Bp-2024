#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b > a) {
        swap(a, b);
    }
    if (b <= 0) {
        return a;
    }
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

void BUILD(int v, int l, int r, vector <long long> &t, vector <long long> &a) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    BUILD(2 * v, l, mid, t, a);
    BUILD(2 * v + 1, mid, r, t, a);
    t[v] = gcd(t[2 * v], t[2 * v + 1]);
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
    t[v] = gcd(t[2 * v], t[2 * v + 1]);
}

long long GET(int v, int vl, int vr, int ql, int qr, vector <long long> &t) {
    if (vl >= qr || vr <= ql) {
        return -1;
    }
    if (vl >= ql && vr <= qr) {
        return t[v];
    }
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t);
    return gcd(res1, res2);
}

int main() {
    int n;
    cin >> n;
    vector <long long> t(4 * n, 0);
    vector <long long> a(n, 0);
    for (int j = 0; j < n; ++j) {
        cin >> a[j];
    }
    BUILD(1, 0, n, t, a);
    int m, l, r;
    string type;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> type >> l >> r;
        if (type == "s") {
            cout << GET(1, 0, n, l - 1, r, t) << " ";
        } else {
            SET(1, 0, n, l - 1, r, t);
        }
    }
}
