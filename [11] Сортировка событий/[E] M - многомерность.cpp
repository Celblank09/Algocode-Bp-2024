//ВСЕ без 1 + ВСЕ без 2 ... - ВСЕ * n
#include <bits/stdc++.h>

using namespace std;

long long const MOD = 998244353;

int main() {
    int n, m, l, r;
    long long res = 0, p_res;
    cin >> n >> m;
    vector <vector <pair <int, int>>> figure(n, vector <pair <int, int>> (m, {0, 0}));
    vector <vector <int>> pref_min(m, vector <int> (n + 2, INT32_MAX));
    vector <vector <int>> pref_max(m, vector <int> (n + 2, INT32_MIN));
    vector <vector <int>> suf_min(m, vector <int> (n + 2, INT32_MAX));
    vector <vector <int>> suf_max(m, vector <int> (n + 2, INT32_MIN));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> l >> r;
            pref_min[j][i + 1] = min(pref_min[j][i], r);
            pref_max[j][i + 1] = max(pref_max[j][i], l);
            figure[i][j] = {l, r};
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            suf_min[j][i + 1] = min(suf_min[j][i + 2], figure[i][j].second);
            suf_max[j][i + 1] = max(suf_max[j][i + 2], figure[i][j].first);
        }
    }
    for (int i = 1; i <= n; ++i) {
        p_res = 1;
        for (int j = 0; j < m; ++j) {
            l = max(pref_max[j][i - 1], suf_max[j][i + 1]);
            r = min(pref_min[j][i - 1], suf_min[j][i + 1]);
            //cout << i << " " << l << " " << r << "\n";
            if (r >= l) {
                p_res *= (r - l + 1);
                p_res %= MOD;
            } else {
                p_res = 0;
            }
        }
        //cout << p_res << "\n";
        res += p_res;
        res %= MOD;
    }
    p_res = n;
    for (int j = 0; j < m; ++j) {
        l = pref_max[j][n];
        r = pref_min[j][n];
        if (r >= l) {
            p_res *= (r - l + 1);
            p_res %= MOD;
        } else {
            p_res = 0;
        }
    }
    //cout << res << " " << p_res << "\n";
    res -= p_res;
    res = ((res % MOD) + MOD) % MOD;
    cout << res;
}
