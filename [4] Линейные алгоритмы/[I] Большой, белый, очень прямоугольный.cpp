#include <bits/stdc++.h>

using namespace std;

long long hist(long long n, vector <long long> &a) {
    vector <pair <long long, long long>> m;
    m.push_back({INT64_MIN, -1});
    vector <long long> res_r(n, n);
    for (int i = 0; i < n; ++i) {
        while (m.back().first > a[i]) {
            res_r[m.back().second] = min((long long)i, n);
            m.pop_back();
        }
        m.push_back({a[i], i});
    }
    m.clear();
    m.push_back({INT64_MIN, -1});
    vector <long long> res_l(n, -1);
    for (int i = n - 1; i >= 0; --i) {
        while (m.back().first > a[i]) {
            res_l[m.back().second] = max(i, -1);
            m.pop_back();
        }
        m.push_back({a[i], i});
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, a[i] * (res_r[i] - res_l[i] - 1));
    }
    return res;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector <vector <long long>> a(n + 1, vector <long long> (m, 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector <vector <long long>> b(n + 1, vector <long long> (m, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1) {
                b[i][j] = 0;
            } else {
                b[i][j] = b[i - 1][j] + 1;
            }
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, hist(m, b[i]));
    }
    cout << res;
}
