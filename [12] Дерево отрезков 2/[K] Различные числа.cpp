#include <bits/stdc++.h>

using namespace std;

struct NODE {
    long long sum;
};

NODE NODE_0 {
        NODE_0.sum = 0,
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

struct req {
    int l;
    int r;
    int number;
    bool operator<(const req &other) const {
        if (r == other.r) {
            return l < other.l;
        }
        return r < other.r;
    }
};

int main() {
    int n, c = 1, dop, q, last_r;
    cin >> n;
    NODE res_p = NODE_0, dop_node = NODE_0;
    vector <NODE> t(4 * n + 12, NODE_0);
    vector <NODE> have(n + 3, NODE_0);
    vector <int> a(n, 0);
    vector <int> last(n + 3, -1);
    BUILD(1, 0, n, t, have);
    map <int, int> compress;
    for (int i = 0; i < n; ++i) {
        cin >> dop;
        if (!compress[dop]) {
            compress[dop] = c;
            c++;
        }
        a[i] = compress[dop];
    }
    cin >> q;
    vector <req> requests(q, {0, 0});
    vector <pair <int, int>> res(q, {0, 0});
    for (int i = 0; i < q; ++i) {
        cin >> requests[i].l >> requests[i].r;
        requests[i].number = i;
        requests[i].l--;
        requests[i].r--;
    }
    sort(requests.begin(), requests.end());
    c = 0;
    last_r = 0;
    for (auto i : requests) {
        while (last_r <= i.r) {
            //cout << last_r << " ";
            if (last[a[last_r]] != -1) {
                dop_node.sum = 0;
                SET(1, 0, n, last[a[last_r]], dop_node, t);
            }
            dop_node.sum = 1;
            SET(1, 0, n, last_r, dop_node, t);
            last[a[last_r]] = last_r;
            last_r++;
        }
        res[c].second = GET(1, 0, n, i.l, i.r + 1, t).sum;
        res[c].first = i.number;
        c++;
    }
    /*cout << "DO: ";
    for (int j = 0; j < n; ++j) {
        cout << GET(1, 0, n, j, j + 1, t).sum << " ";
    }
    cout << "\n";*/
    sort(res.begin(), res.end());
    for (auto i : res) {
        cout << i.second << "\n";
    }
}
