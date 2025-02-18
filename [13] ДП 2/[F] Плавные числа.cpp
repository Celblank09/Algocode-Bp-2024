#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long res = 0;
    cin >> n;
    vector <vector <long long>> dp(n + 1, vector <long long> (10, 0));
    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j + 1 <= 9) {
                dp[i][j] += dp[i - 1][j + 1];
            }
        }
    }
    for (int i = 0; i <= 9; ++i) {
        res += dp[n][i];
    }
    cout << res;
}
