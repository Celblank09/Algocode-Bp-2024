#include <bits/stdc++.h>

using namespace std;

struct NODE {
    //что-то
};

NODE MERGE(NODE l, NODE r) {
    NODE res;
    //что-то как-то меняется
    return res;
}

NODE NODE_0 {
        //NODE_0.что_то = чему_то;
};

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
    int n;
    cin >> n;
    NODE res;
    vector <NODE> t(4 * n, NODE_0);
    vector <NODE> a(n, NODE_0);
    for (int j = 0; j < n; ++j) {
        //записать в NODE
    }
    BUILD(1, 0, n, t, a);
    int m, l, r, ind;
    NODE x;
    string type;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> type;
        if (type == "1") {
            cin >> l >> r;
            res = GET(1, 0, n, l - 1, r, t);
        } else {
            cin >> ind; //Ввести значение в NODE;
            SET(1, 0, n, ind, x, t);
        }
    }
}
