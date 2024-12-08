#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << fixed << setprecision(10);
    int n, W;
    cin >> n >> W;
    vector <int> m(n + 1, 0);
    vector <double> c(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> m[i] >> c[i];
    }
    vector <vector <double>> dp1(n + 1, vector <double>(W + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j - m[i] >= 0 && dp1[i - 1][j] <= dp1[i - 1][j - m[i]] + c[i]) {
                dp1[i][j] = dp1[i - 1][j - m[i]] + c[i];
            } else {
                dp1[i][j] = dp1[i - 1][j];
            }
        }
    }
    vector <vector <double>> dp2(n + 2, vector <double>(W + 1, 0));
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= W; ++j) {
            if (j - m[i] >= 0 && dp2[i + 1][j] <= dp2[i + 1][j - m[i]] + c[i]) {
                dp2[i][j] = dp2[i + 1][j - m[i]] + c[i];
            } else {
                dp2[i][j] = dp2[i + 1][j];
            }
        }
    }
    vector <vector <double>> suf_max(n + 2, vector <double> (W + 1, 0));
    for (int i = 1; i <= n; ++i) {
        suf_max[i][0] = dp2[i][0];
        for (int j = 1; j <= W; ++j) {
            suf_max[i][j] = max(dp2[i][j], suf_max[i][j - 1]);
        }
    }
    double res;
    for (int i = 1; i <= n; ++i) {
        res = 0;
        for (int w1 = 0; w1 <= W; ++w1) {
            res = max(res, dp1[i - 1][w1] + suf_max[i + 1][W - w1]);
        }
        cout << res << "\n";
    }
}
