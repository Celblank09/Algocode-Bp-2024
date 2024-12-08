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
    if (W % 2 == 1 || n % 2 == 1) {
        cout << -1;
        return 0;
    }
    vector <vector <vector <bool>>> dp(n + 1, vector <vector <bool>> (W + 1, vector <bool> (n + 1, false)));
    dp[0][0][0] = true;
    for (long long i = 1; i <= n; ++i) {
        for (long long w = 0; w <= W; ++w) {
            for (long long cnt = 0; cnt <= i; ++cnt) {
                if (cnt == 0) {
                    dp[i][w][cnt] = dp[i - 1][w][cnt];
                    continue;
                }
                if (w - m[i] < 0) {
                    dp[i][w][cnt] = dp[i - 1][w][cnt];
                } else {
                    dp[i][w][cnt] = dp[i - 1][w][cnt] | dp[i - 1][w - m[i]][cnt - 1];
                }
            }
        }
    }
    if (!dp[n][W / 2][n / 2]) {
        cout << -1;
        return 0;
    }
    long long cur_w1 = W / 2, cur_cnt1 = n / 2;
    vector <long long> res1;
    vector <long long> res2;
    for (long long i = n; i >= 1; --i) {
        if (cur_w1 - m[i] >= 0 && cur_cnt1 >= 1 && dp[i - 1][cur_w1 - m[i]][cur_cnt1 - 1]) {
            cur_w1 -= m[i];
            cur_cnt1--;
            res1.push_back(i);
        } else {
            res2.push_back(i);
        }
    }
    for (long long i : res1) {
        cout << i << " ";
    }
    cout << "\n";
    for (long long i : res2) {
        cout << i << " ";
    }
}
