#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector <long long> a(n, 0);
    vector <long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    vector <pair <long long, long long>> pref_min(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i) {
        if (pref[i] < pref_min[i - 1].second) {
            pref_min[i] = {i, pref[i]};
        } else {
            pref_min[i] = pref_min[i - 1];
        }
    }
    long long res = a[0];
    long long res_l = 0;
    long long res_r = 1;
    for (int i = 1; i <= n; ++i) {
        if (i == pref_min[i].first) {
            if (res < a[i - 1]) {
                res = a[i - 1];
                res_l = i - 1;
                res_r = i;
            }
        } else if (res < pref[i] - pref_min[i].second) {
            res = pref[i] - pref_min[i].second;
            res_l = pref_min[i].first;
            res_r = i;
        }
    }
    cout << res_l + 1 << " " << res_r << " " << res;
}
