#include <bits/stdc++.h>

using namespace std;

struct NODE {
    long long min;
    long long push;
    long long yl;
    long long yr;
    long long c;
};

NODE NODE_0 {
        NODE_0.min = INT64_MAX,
        NODE_0.push = 0,
        NODE_0.yl = 0,
        NODE_0.yr = 0,
        NODE_0.c = 0
};

void apply(int v, long long x, vector <NODE> &t) {
    t[v].min += x;
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
    t[v].min = min(t[2 * v].min, t[2 * v + 1].min);
    t[v].c = 0;
    if (t[2 * v].min == t[v].min) {
        t[v].c = t[2 * v].c;
    }
    if (t[2 * v + 1].min == t[v].min) {
        t[v].c += t[2 * v + 1].c;
    }
    t[v].yl = t[2 * v].yl;
    t[v].yr = t[2 * v + 1].yr;
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
    t[v].min = min(t[2 * v].min, t[2 * v + 1].min);
    t[v].c = 0;
    if (t[2 * v].min == t[v].min) {
        t[v].c += t[2 * v].c;
    }
    if (t[2 * v + 1].min == t[v].min) {
        t[v].c += t[2 * v + 1].c;
    }
    t[v].yl = t[2 * v].yl;
    t[v].yr = t[2 * v + 1].yr;
}

NODE GET(int v, int vl, int vr, int ql, int qr, vector <NODE> &t) { //кол-во 0
    if (vl >= qr || vr <= ql) {
        auto res = t[v];
        res.c = 0;
        return res;
    }
    if (vl >= ql && vr <= qr) {
        return t[v];
    }
    push(v, t);
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t);
    NODE res = NODE_0;
    res.min = min(res1.min, res2.min);
    res.yl = res1.yl;
    res.yr = res2.yr;
    if (res1.min < res2.min) {
        res.c = res1.c;
    } else if (res1.min > res2.min) {
        res.c = res2.c;
    } else {
        res.c = res1.c + res2.c;
    }
    return res;
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
    int m, x1, x2, y1, y2;
    cin >> m;
    vector <rect> rects(m, {0, 0, 0, 0});
    set <int> p_compress;
    map <int, int> compress;
    set <int> s_y;
    vector <int> ls_y;
    s_y.insert(INT32_MIN);
    s_y.insert(INT32_MAX);
    p_compress.insert(INT32_MIN);
    p_compress.insert(INT32_MAX);
    for (int i = 0; i < m; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        p_compress.insert(y1);
        p_compress.insert(y2);
        s_y.insert(y1);
        s_y.insert(y2);
        rects[i] = {x1, x2, y1, y2};
    }
    int c = 0;
    for (auto i : p_compress) {
        compress[i] = c;
        c++;
    }
    for (auto i : s_y) {
        ls_y.push_back(i);
    }
    vector <event> events;
    for (int i = 0; i < m; ++i) {
        events.push_back({rects[i].x1, compress[rects[i].y1], compress[rects[i].y2], -1, i});
        events.push_back({rects[i].x2, compress[rects[i].y1], compress[rects[i].y2], 1, i});
    }
    sort(events.begin(), events.end());
    NODE x = NODE_0;
    int n = p_compress.size();
    vector <NODE> t(4 * n + 4, NODE_0);
    vector <NODE> build(n, NODE_0);
    for (int i = 0; i < n; ++i) {
        build[i].yl = ls_y[i];
        build[i].yr = ls_y[i + 1];
        build[i].c = build[i].yr - build[i].yl;
        build[i].min = 0;
    }
    long long ans = 0;
    BUILD(1, 0, n, t, build);
    //cout << GET(1, 0, n, 0, n, t).c << "\n";
    for (int i = 0; i < events.size(); ++i) {
        if (i != 0) {
            ans += (events[i].x - events[i - 1].x) * (t[1].yr - t[1].yl - GET(1, 0, n, 0, n, t).c);
        }
        if (events[i].type == -1) {
            SET(1, 0, n, events[i].y1, events[i].y2, 1, t);
        } else {
            SET(1, 0, n, events[i].y1, events[i].y2, -1, t);
        }
        //cout << GET(1, 0, n, 0, n, t).c << " " << events[i].y1 << " " << events[i].y2 << "\n";
    }
    cout << ans;
}
