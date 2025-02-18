#include <bits/stdc++.h>

using namespace std;

void SET(int v, int l, int r, int ind, int x, vector <int> &t) {
    if (l + 1 == r) {
        t[v] += x;
        return;
    }
    int mid = (l + r) / 2;
    if (ind < mid) {
        SET(2 * v, l, mid, ind, x, t);
    } else {
        SET(2 * v + 1, mid, r, ind, x, t);
    }
    t[v] = t[2 * v] + t[2 * v + 1];
}

int GET(int v, int vl, int vr, int ql, int qr, vector <int> &t) {
    if (vl >= qr || vr <= ql) {
        return 0;
    }
    if (vl >= ql && vr <= qr) {
        return t[v];
    }
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t);
    return res1 + res2;
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n, 0);
    vector <vector <int>> dp(2, vector <int> (n, 0));
    dp[0] = vector <int> (n, 1);
    vector <vector <int>> dp2(2, vector <int> (n, 0));
    dp2[0] = vector <int> (n, 1);
    for (int j = 0; j < n; ++j) {
        cin >> a[j];
        a[j] = -a[j];
    }
    auto b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    map <int, int> compress;
    for (int i = 0; i < b.size(); ++i) {
        compress[b[i]] = i;
    }
    vector <int> t(4 * b.size(), 0);
    for (int i = 0; i < n; ++i) {
        dp[1][i] = GET(1, 0, n, 0, compress[a[i]], t);
        SET(1, 0, n, compress[a[i]], dp[0][i], t);
    }
    t = vector <int> (4 * b.size(), 0);
    for (int i = n - 1; i >= 0; --i) {
        dp2[1][i] = GET(1, 0, n, compress[a[i]] + 1, n, t);
        SET(1, 0, n, compress[a[i]], dp2[0][i], t);
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += ((long long)dp[1][i]) * dp2[1][i];
    }
    cout << res;
}
