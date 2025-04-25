#include <bits/stdc++.h>

using namespace std;

struct NODE {
    long long sum;
    long long l;
    long long r;
    long long push;
    long long push_type;
};

NODE NODE_0 {
        NODE_0.sum = 0,
        NODE_0.l = 0,
        NODE_0.r = 0,
        NODE_0.push = 0,
        NODE_0.push_type = 0
};

void apply(int v, long long x, long long type, vector <NODE> &t) {
    if (t[v].push_type == 0) {
        if (type == 1) {
            t[v].push_type = 1;
            t[v].push = x;
            t[v].sum = (t[v].r - t[v].l) * x;
        } else {
            t[v].push_type = 2;
            t[v].push += x;
            t[v].sum += (t[v].r - t[v].l) * x;
        }
    } else if (t[v].push_type == 1) {
        if (type == 1) {
            t[v].push_type = 1;
            t[v].push = x;
            t[v].sum = (t[v].r - t[v].l) * x;
        } else {
            t[v].push_type = 1;
            t[v].push += x;
            t[v].sum += (t[v].r - t[v].l) * x;
        }
    } else {
        if (type == 1) {
            t[v].push_type = 1;
            t[v].push = x;
            t[v].sum = (t[v].r - t[v].l) * x;
        } else {
            t[v].push_type = 2;
            t[v].push += x;
            t[v].sum += (t[v].r - t[v].l) * x;
        }
    }
}

void push(int v, vector <NODE> &t) {
    apply(2 * v, t[v].push, t[v].push_type, t);
    apply(2 * v + 1, t[v].push, t[v].push_type, t);
    t[v].push = 0;
    t[v].push_type = 0;
}

void BUILD(int v, int l, int r, vector <NODE> &t) {
    if (l + 1 == r) {
        t[v].sum = 0;
        t[v].l = l;
        t[v].r = r;
        return;
    }
    int mid = (l + r) / 2;
    BUILD(2 * v, l, mid, t);
    BUILD(2 * v + 1, mid, r, t);
    t[v].l = t[2 * v].l;
    t[v].r = t[2 * v + 1].r;
    t[v].sum = t[2 * v].sum + t[2 * v + 1].sum;
}

void SET(int v, int vl, int vr, int ql, int qr, long long x, long long type, vector <NODE> &t) {
    if (vl >= qr || vr <= ql) {
        return;
    }
    if (vl >= ql && vr <= qr) {
        apply(v, x, type, t);
        return;
    }
    push(v, t);
    int mid = (vl + vr) / 2;
    SET(2 * v, vl, mid, ql, qr, x, type, t);
    SET(2 * v + 1, mid, vr, ql, qr, x, type, t);
    t[v].sum = t[2 * v].sum + t[2 * v + 1].sum;
}

long long GET(int v, int vl, int vr, int ql, int qr, vector <NODE> &t) {
    if (vl >= qr || vr <= ql) {
        return 0;
    }
    if (vl >= ql && vr <= qr) {
        return t[v].sum;
    }
    push(v, t);
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t);
    return res1 + res2;
}

int main() {
    long long n, l, r, add, m;
    char type;
    cin >> n;
    vector <NODE> t(8 * n + 12, NODE_0);
    BUILD(1, 0, n, t);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> type;
        if (type == '1') {
            cin >> l >> r >> add;
            SET(1, 0, n, l, r, add, 1, t);
        } else if (type == '2') {
            cin >> l >> r >> add;
            SET(1, 0, n, l, r, add, 2, t);
        } else {
            cin >> l >> r;
            cout << GET(1, 0, n, l, r, t) << "\n";
        }
        /*for (int j = 0; j < n; ++j) {
            cout << GET(1, 0, n, j, j + 1, t) << " ";
        }
        cout << "\n";*/
    }
}
