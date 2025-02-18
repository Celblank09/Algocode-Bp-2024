#include <bits/stdc++.h>

using namespace std;

long long mod = INT64_MAX;

void BUILD(int v, int l, int r, vector <int> &t, vector <int> &a) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    BUILD(2 * v, l, mid, t, a);
    BUILD(2 * v + 1, mid, r, t, a);
    t[v] = (t[2 * v] + t[2 * v + 1]) % mod;
}

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
    t[v] = (t[2 * v] + t[2 * v + 1]) % mod;
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
    return (res1 + res2) % mod;
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n, 0);
    vector <vector <int>> dp(2, vector <int> (n, 0));
    dp[0] = vector <int> (n, 1);
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
    int max_r;
    while (true) {
        max_r = 0;
        vector <int> t(4 * b.size(), 0);
        for (int i = 0; i < n; ++i) {
            dp[1][i] = GET(1, 0, n, 0, compress[a[i]], t);
            max_r = max(max_r, dp[1][i]);
            SET(1, 0, n, compress[a[i]], dp[0][i], t);
        }
        break;
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += dp[1][i];
    }
    cout << res;
}
