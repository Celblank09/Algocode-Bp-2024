#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> m(n, 0);
    vector<int> c(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<pair<int, vector<int>>>> dp(n + 1, vector<pair<int, vector<int>>>(w + 1, pair<int, vector<int>>(0, vector<int>())));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            if (j - m[i - 1] >= 0) {
                if (dp[i - 1][j].first <= dp[i - 1][j - m[i - 1]].first + c[i - 1]) {
                    dp[i][j].first = dp[i - 1][j - m[i - 1]].first + c[i - 1];
                    dp[i][j].second = dp[i - 1][j - m[i - 1]].second;
                    dp[i][j].second.push_back(i);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][w].second.size() << "\n";
    for (int i : dp[n][w].second) {
        cout << i << " ";
    }
}
