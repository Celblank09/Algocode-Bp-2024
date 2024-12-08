#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> m(n, 0);
    vector<int> c(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> m[i] >> c[i];
    }
    vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(10001,
                                                                                                pair<int, vector<int>>(
                                                                                                        1e8,
                                                                                                        vector<int>())));
    dp[0][0].first = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 10000; ++j) {
            if (j - c[i - 1] >= 0) {
                if (dp[i - 1][j].first > dp[i - 1][j - c[i - 1]].first + m[i - 1]) {
                    dp[i][j].first = dp[i - 1][j - c[i - 1]].first + m[i - 1];
                    dp[i][j].second = dp[i - 1][j - c[i - 1]].second;
                    dp[i][j].second.push_back(i);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (long long i = 10000; i >= 0; --i) {
        if (dp[n][i].first <= w && !dp[n][i].second.empty()) {
            cout << i << "\n";
            cout << dp[n][i].second.size() << "\n";
            for (int j : dp[n][i].second) {
                cout << j << " ";
            }
            return 0;
        }
    }
    cout << "0\n0";
}
