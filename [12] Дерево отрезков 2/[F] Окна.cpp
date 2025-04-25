#include <bits/stdc++.h>

using namespace std;

struct NODE {
    long long sum;
    long long push;
    long long y;
};

NODE NODE_0 {
        NODE_0.sum = 0,
        NODE_0.push = 0,
        NODE_0.y = 0
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
    if (t[2 * v].sum > t[2 * v + 1].sum) {
        t[v].y = t[2 * v].y;
    } else {
        t[v].y = t[2 * v + 1].y;
    }
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
    if (t[2 * v].sum > t[2 * v + 1].sum) {
        t[v].y = t[2 * v].y;
    } else {
        t[v].y = t[2 * v + 1].y;
    }
    t[v].sum = max(t[2 * v].sum, t[2 * v + 1].sum);
}

NODE GET(int v, int vl, int vr, int ql, int qr, vector <NODE> &t) {
    if (vl >= qr || vr <= ql) {
        return NODE_0;
    }
    if (vl >= ql && vr <= qr) {
        return t[v];
    }
    push(v, t);
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t);
    if (res1.sum > res2.sum) {
        return res1;
    }
    return res2;
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
    int ans = -1, ans_y, ans_x;
    for (int i = 0; i < m; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        rects[i] = {x1, x2, y1, y2};
    }
    vector <event> events;
    for (int i = 0; i < m; ++i) {
        events.push_back({rects[i].x1, rects[i].y1, rects[i].y2, -1, i});
        events.push_back({rects[i].x2, rects[i].y1, rects[i].y2, 1, i});
    }
    sort(events.begin(), events.end());
    NODE x = NODE_0;
    int n = 2 * 1'000'000 + 1'000;
    vector <NODE> t(n * 4 + 4, NODE_0);
    vector <NODE> build(n, NODE_0);
    for (int i = 0; i < n; ++i) {
        build[i].y = i;
        build[i].sum = 0;
    }
    BUILD(1, 0, n, t, build);
    for (auto i : events) {
        if (i.type == -1) {
            SET(1, 0, n, i.y1 + 1'000'000, i.y2 + 1 + 1'000'000, 1, t);
        } else {
            SET(1, 0, n, i.y1 + 1'000'000, i.y2 + 1 + 1'000'000, -1, t);
        }
        //cout << GET(1, 0, n, 0, n, t).sum << "\n";
        if (GET(1, 0, n, 0, n, t).sum > ans) {
            ans = GET(1, 0, n, 0, n, t).sum;
            ans_x = i.x;
            ans_y = GET(1, 0, n, 0, n, t).y - 1'000'000;
        }
    }
    cout << ans << "\n";
    cout << ans_x << " " << ans_y;
}
