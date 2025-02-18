#include <bits/stdc++.h>

using namespace std;

int MOD = 1'000'000'007;

int calc(string a) {
    vector<vector<vector<int>>> dp(a.size() + 1, vector<vector<int>>
            (2, vector<int>(10, 0)));
    //dp[len][flag][last]
    dp[1][1][a[0] - '0'] = 1;
    for (int i = 1; i < a[0] - '0'; ++i) {
        dp[1][0][i] = 1;
    }
    for (int i = 2; i <= a.size(); ++i) {
        for (int l = 0; l <= 9; ++l) {
            for (int j = 0; j <= l; ++j) {
                dp[i][0][l] = (dp[i][0][l] + dp[i - 1][0][j]) % MOD;
            }
            for (int j = 0; j <= min(l, (a[i - 1] - '0') - 1); ++j) {
                if (l < a[i - 1] - '0') {
                    dp[i][0][l] = (dp[i][0][l] + dp[i - 1][1][j]) % MOD;
                }
            }
        }
        if (a[i - 1] >= a[i - 2]) {
            dp[i][1][a[i - 1] - '0'] = dp[i - 1][1][a[i - 2] - '0'];
        }
    }
    int res = 0;
    for (int l = 0; l <= 9; ++l) {
        res = (res + dp[a.size()][0][l]) % MOD;
        res = (res + dp[a.size()][1][l]) % MOD;
    }
    /*
    for (int i = 1; i <= a.size(); ++i) {
        for (int l = 0; l <= 9; ++l) {
            cout << dp[i][0][l] << " ";
        }
        cout << "| ";
        for (int l = 0; l <= 9; ++l) {
            cout << dp[i][1][l] << " ";
        }
        cout << "\n";
    }
    */
    vector <vector <int>> dp_2(a.size(), vector <int> (10, 0));
    for (int i = 1; i <= 9; ++i) {
        dp_2[0][i] = 1;
    }
    for (int i = 1; i < a.size() - 1; ++i) {
        for (int l = 1; l <= 9; ++l) {
            for (int j = 1; j <= l; ++j) {
                dp_2[i][l] = (dp_2[i][l] + dp_2[i - 1][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < a.size() - 1; ++i) {
        for (int l = 1; l <= 9; ++l) {
            res = (res + dp_2[i][l]) % MOD;
        }
    }
    return res;
}

int main() {
    bool flag = true;
    string l, r;
    cin >> l >> r;
    int res = ((calc(r) - calc(l)) % MOD + MOD) % MOD;
    for (int i = 1; i < l.size(); ++i) {
        if (l[i] < l[i - 1]) {
            flag = false;
            break;
        }
    }
    cout << res + flag;
    return 0;
}
