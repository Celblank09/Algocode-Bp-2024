#include <bits/stdc++.h>

using namespace std;

struct NODE {
    int len;
    long long ans;
    long long suf;
    long long pref;
    long long sum;
};

NODE NODE_0 {
        NODE_0.len = 0,
        NODE_0.ans = 0,
        NODE_0.suf = 0,
        NODE_0.pref = 0,
        NODE_0.sum = 0
};

NODE MERGE(NODE &l, NODE &r) {
    NODE res = NODE_0;
    res.len = l.len + r.len;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suf = max(r.suf, r.sum + l.suf);
    res.ans = max(l.suf + r.pref, max(l.ans, r.ans));
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
        t[v] = x;
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
    cin >> n >> m;
    NODE res = NODE_0;
    vector <NODE> t(4 * n, NODE_0);
    vector <NODE> a(n, NODE_0);
    for (int j = 0; j < n; ++j) {
        cin >> dop;
        a[j].len = 1;
        a[j].ans = dop;
        a[j].pref = dop;
        a[j].suf = dop;
        a[j].sum = dop;
    }
    BUILD(1, 0, n, t, a);
    int l, r, ind;
    NODE x = NODE_0;
    string type;
    for (int j = 0; j < m; ++j) {
        cin >> type;
        if (type == "get") {
            cin >> l >> r;
            res = GET(1, 0, n, l - 1, r, t);
            cout << max(res.ans, (long long)0) << "\n";
        } else {
            cin >> ind >> dop;
            x.len = 1;
            x.ans = dop;
            x.pref = dop;
            x.suf = dop;
            x.sum = dop;
            SET(1, 0, n, ind - 1, x, t);
        }
    }
}
