#include <bits/stdc++.h>

using namespace std;

bool check(long long m, long long k, vector <long long> a) {
    long long res = 1, prev = a[0];
    for (int i = 1; i < a.size(); ++i) {
        if (abs(a[i] - prev) >= m) {
            res++;
            prev = a[i];
        }
    }
    return res < k;
}

int main() {
    long long n, k, l = 1, r = 1'000'000'000, m;
    cin >> n >> k;
    vector <long long> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (l + 1 < r) {
        m = (l + r) / 2;
        if (check(m, k, a)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l;
}
