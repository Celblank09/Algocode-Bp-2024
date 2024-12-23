#include <bits/stdc++.h>

using namespace std;

struct NODE {
    int len;
    int ans;
    int suf;
    int pref;
};

NODE NODE_0 {
        NODE_0.len = 0,
        NODE_0.ans = 0,
        NODE_0.suf = 0,
        NODE_0.pref = 0
};

NODE MERGE(NODE &l, NODE &r) {
    NODE res = NODE_0;
    res.len = l.len + r.len;
    res.ans = max(l.suf + r.pref, max(l.ans, r.ans));
    res.pref = l.pref;
    res.suf = r.suf;
    if (l.len == l.pref) {
        res.pref += r.pref;
    }
    if (r.len == r.suf) {
        res.suf += l.suf;
    }
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
    int n, dop;
    cin >> n;
    NODE res = NODE_0;
    vector <NODE> t(4 * n, NODE_0);
    vector <NODE> a(n, NODE_0);
    for (int j = 0; j < n; ++j) {
        cin >> dop;
        if (dop == 0) {
            a[j].len = 1;
            a[j].ans = 1;
            a[j].pref = 1;
            a[j].suf = 1;
        } else {
            a[j].len = 1;
            a[j].ans = 0;
            a[j].pref = 0;
            a[j].suf = 0;
        }
    }
    BUILD(1, 0, n, t, a);
    int m, l, r, ind;
    NODE x = NODE_0;
    string type;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> type;
        if (type == "QUERY") {
            cin >> l >> r;
            res = GET(1, 0, n, l - 1, r, t);
            cout << res.ans << "\n";
        } else {
            cin >> ind >> dop;
            if (dop == 0) {
                x.len = 1;
                x.ans = 1;
                x.pref = 1;
                x.suf = 1;
            } else {
                x.len = 1;
                x.ans = 0;
                x.pref = 0;
                x.suf = 0;
            }
            SET(1, 0, n, ind - 1, x, t);
        }
    }
}
