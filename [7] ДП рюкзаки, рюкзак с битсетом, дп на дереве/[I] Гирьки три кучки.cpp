#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, W = 0;
    cin >> n;
    vector <long long> m(n + 1, 0);
    for (long long i = 1; i <= n; ++i) {
        cin >> m[i];
        W += m[i];
    }
    if (W % 3 != 0) {
        cout << -1;
        return 0;
    }
    vector <vector <vector <bool>>> dp(n + 1, vector <vector <bool>> (W / 3 + 1, vector <bool> (W / 3 + 1, false)));
    dp[0][0][0] = true;
    for (long long i = 1; i <= n; ++i) {
        for (long long w1 = 0; w1 <= W / 3; ++w1) {
            for (long long w2 = 0; w2 <= W / 3; ++w2) {
                if (w1 - m[i] >= 0) {
                    dp[i][w1][w2] = dp[i - 1][w1 - m[i]][w2] | dp[i - 1][w1][w2] | dp[i][w1][w2];
                } else {
                    dp[i][w1][w2] = dp[i - 1][w1][w2] | dp[i][w1][w2];
                }
                if (w2 - m[i] >= 0) {
                    dp[i][w1][w2] = dp[i - 1][w1][w2 - m[i]] | dp[i - 1][w1][w2] | dp[i][w1][w2];
                } else {
                    dp[i][w1][w2] = dp[i - 1][w1][w2] | dp[i][w1][w2];
                }
            }
        }
    }
    if (!dp[n][W / 3][W / 3]) {
        cout << -1;
        return 0;
    }
    long long cur_w1 = W / 3, cur_w2 = W / 3;
    vector <long long> res1, res2, res3;
    for (long long i = n; i >= 1; --i) {
        if (cur_w1 - m[i] >= 0 && dp[i - 1][cur_w1 - m[i]][cur_w2]) {
            cur_w1 -= m[i];
            res1.push_back(i);
            continue;
        }
        if (cur_w2 - m[i] >= 0 && dp[i - 1][cur_w1][cur_w2 - m[i]]) {
            cur_w2 -= m[i];
            res2.push_back(i);
            continue;
        }
        res3.push_back(i);
    }
    cout << res1.size() << " ";
    for (long long i : res1) {
        cout << i << " ";
    }
    cout << "\n";
    cout << res2.size() << " ";
    for (long long i : res2) {
        cout << i << " ";
    }
    cout << "\n";
    cout << res3.size() << " ";
    for (long long i : res3) {
        cout << i << " ";
    }
    cout << "\n";
}
