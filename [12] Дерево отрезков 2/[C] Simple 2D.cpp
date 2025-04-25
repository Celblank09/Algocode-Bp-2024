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
        t[v] = MERGE(t[v], x);
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

struct event {
    int x;
    int y1;
    int y2;
    int type; //   -1 - OPEN, 0 - POINT, 1 - CLOSE
    int index;
    bool operator<(const event &other) const {
        if (x == other.x) {
            return type < other.type;
        }
        return x < other.x;
    }
};

struct rect {
    int x1;
    int x2;
    int y1;
    int y2;
};

int main() {
    int n, m, x1, x2, y1, y2;
    cin >> n;
    set <int> p_compress;
    map <int, int> compress;
    vector <pair <int, int>> points(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        cin >> x1 >> y1;
        p_compress.insert(x1);
        p_compress.insert(y1);
        points[i] = {x1, y1};
    }
    cin >> m;
    vector <rect> rects(m, {0, 0, 0, 0});
    vector <int> ans(m, 0);
    for (int i = 0; i < m; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        p_compress.insert(x1);
        p_compress.insert(x2);
        p_compress.insert(y1);
        p_compress.insert(y2);
        rects[i] = {x1, x2, y1, y2};
    }
    int c = 0;
    for (auto i : p_compress) {
        compress[i] = c;
        c++;
    }
    vector <NODE> t(p_compress.size() * 4 + 4, NODE_0);
    vector <event> events;
    for (int i = 0; i < n; ++i) {
        events.push_back({compress[points[i].first], compress[points[i].second], compress[points[i].second], 0, 0});
    }
    for (int i = 0; i < m; ++i) {
        events.push_back({compress[rects[i].x1], compress[rects[i].y1], compress[rects[i].y2], -1, i});
        events.push_back({compress[rects[i].x2], compress[rects[i].y1], compress[rects[i].y2], 1, i});
    }
    sort(events.begin(), events.end());
    NODE x = NODE_0;
    n = p_compress.size();
    for (auto i : events) {
        if (i.type == 0) {
            x.sum = 1;
            SET(1, 0, n, i.y1, x, t);
        } else if (i.type == -1) {
            ans[i.index] -= GET(1, 0, n, i.y1, i.y2 + 1, t).sum;
            //cout << i.index << " OPEN " << GET(1, 0, n, i.y1, i.y2 + 1, t).sum << "\n";
        } else {
            ans[i.index] += GET(1, 0, n, i.y1, i.y2 + 1, t).sum;
            //cout << i.index << " CLOSE " << GET(1, 0, n, i.y1, i.y2 + 1, t).sum << "\n";
        }
    }
    for (int i : ans) {
        cout << i << "\n";
    }
}
