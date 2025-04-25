#include <bits/stdc++.h>

using namespace std;

struct NODE {
    long long sum;
    long long push;
};

NODE NODE_0 {
        NODE_0.sum = INT64_MIN,
        NODE_0.push = 0
};

void apply(int v, long long x, vector <NODE> &t) {
    t[v].sum += x;
    t[v].push += x;
}

void push(int v, vector <NODE> &t) {
    apply(2 * v, t[v].push, t);
    apply(2 * v + 1, t[v].push, t);
    t[v].push = 0;
}

void BUILD(int v, int l, int r, vector <NODE> &t, vector <NODE> &a) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    BUILD(2 * v, l, mid, t, a);
    BUILD(2 * v + 1, mid, r, t, a);
    t[v].sum = max(t[2 * v].sum, t[2 * v + 1].sum);
}

void SET(int v, int vl, int vr, int ql, int qr, long long x, vector <NODE> &t) {
    if (vl >= qr || vr <= ql) {
        return;
    }
    if (vl >= ql && vr <= qr) {
        apply(v, x, t);
        return;
    }
    push(v, t);
    int mid = (vl + vr) / 2;
    SET(2 * v, vl, mid, ql, qr, x, t);
    SET(2 * v + 1, mid, vr, ql, qr, x, t);
    t[v].sum = max(t[2 * v].sum, t[2 * v + 1].sum);
}

long long GET(int v, int vl, int vr, int ql, int qr, vector <NODE> &t) {
    if (vl >= qr || vr <= ql) {
        return INT64_MIN;
    }
    if (vl >= ql && vr <= qr) {
        return t[v].sum;
    }
    push(v, t);
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t);
    return max(res1, res2);
}

int main() {
    long long n, dop, l, r, add, m;
    char type;
    cin >> n;
    vector <NODE> a(n, NODE_0);
    vector <NODE> t(8 * n + 12, NODE_0);
    for (int i = 0; i < n; ++i) {
        cin >> dop;
        a[i].sum = dop;
    }
    BUILD(1, 0, n, t, a);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> type;
        if (type == 'a') {
            cin >> l >> r >> add;
            SET(1, 0, n, l - 1, r, add, t);
        } else {
            cin >> l >> r;
            cout << GET(1, 0, n, l - 1, r, t) << " ";
        }
    }
}
