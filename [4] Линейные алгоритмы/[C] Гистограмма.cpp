#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector <long long> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
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
    cout << res;
}
