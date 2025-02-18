#include <bits/stdc++.h>

using namespace std;

struct NODE {
    long long sum;
};

NODE NODE_0 {
        NODE_0.sum = 0
};

NODE MERGE(NODE &l, NODE &r) {
    NODE res = NODE_0;
    res.sum = l.sum + r.sum;
    return res;
}

void BUILD(int v, int l, int r, vector <NODE> &t, vector <NODE> &a) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    BUILD(2 * v, l, mid, t, a);
    BUILD(2 * v + 1, mid, r, t, a);
    t[v] = MERGE(t[2 * v], t[2 * v + 1]);
}

void SET(int v, int l, int r, int ind, NODE x, vector <NODE> &t) {
    if (l + 1 == r) {
        t[v].sum += x.sum;
        return;
    }
    int mid = (l + r) / 2;
    if (ind < mid) {
        SET(2 * v, l, mid, ind, x, t);
    } else {
        SET(2 * v + 1, mid, r, ind, x, t);
    }
    t[v] = MERGE(t[2 * v], t[2 * v + 1]);
}

NODE GET(int v, int vl, int vr, int ql, int qr, vector <NODE> &t) {
    if (vl >= qr || vr <= ql) {
        return NODE_0;
    }
    if (vl >= ql && vr <= qr) {
        return t[v];
    }
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t);
    return MERGE(res1, res2);
}

int main() {
    int n, m, dop;
    cin >> n;
    NODE res = NODE_0;
    vector <NODE> t(4 * n + 4, NODE_0);
    vector <NODE> a(n + 1, NODE_0);
    vector <int> start(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> start[i];
    }
    a[0].sum = start[0];
    for (int j = 1; j < n; ++j) {
        a[j].sum = start[j] - start[j - 1];
    }
    n++;
    cin >> m;
    BUILD(1, 0, n, t, a);
    int l, r, ind, add;
    NODE x = NODE_0;
    string type;
    for (int j = 0; j < m; ++j) {
        cin >> type;
        if (type == "g") {
            cin >> ind;
            res = GET(1, 0, n, 0, ind, t);
            cout << res.sum << "\n";
        } else {
            cin >> l >> r >> add;
            x.sum = add;
            SET(1, 0, n, l - 1, x, t);
            x.sum = -add;
            SET(1, 0, n, r, x, t);
        }
    }
}
