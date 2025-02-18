#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector <vector <int>> dp(a.size() + 1, vector <int> (b.size() + 1, 0));
    for (int i = 0; i <= a.size(); ++i) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= b.size(); ++i) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1]));
            } else {
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
            }
        }
    }
    /*for (auto i : dp) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }*/
    cout << dp[a.size()][b.size()];
}
