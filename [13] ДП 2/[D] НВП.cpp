#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a1, k, b, m;
    cin >> n >> a1 >> k >> b >> m;
    vector <int> a(n, 0);
    vector <int> dp(n + 2, INT32_MAX);
    map <int, int> pred;
    dp[0] = INT32_MIN;
    a[0] = a1;
    for (int i = 1; i < n; ++i) {
        a[i] = (k * a[i - 1] + b) % m;
    }
    /*
    for (int i : a) {
        cout << i << " ";
    }
    cout << "\n";
    */
    for (int i = 0; i < n; ++i) {
        int l = 0, r = n + 1, mid;
        while (l + 1 != r) {
            mid = (l + r) / 2;
            if (dp[mid] == INT32_MAX || (dp[mid] != INT32_MIN && a[dp[mid]] >= a[i])) {
                r = mid;
            } else {
                l = mid;
            }
        }
        pred[i] = dp[r - 1];
        dp[r] = i;
        /*
        for (int j = 1; j <= n; ++j) {
            if (dp[j] == INT32_MAX) {
                break;
            }
            cout << a[dp[j]] << " ";
        }
        cout << " | ";
        for (auto j : pred) {
            if (j.second == INT32_MIN) {
                cout << a[j.first] << ": INF ";
            } else {
                cout << a[j.first] << ": " << a[j.second] << " ";
            }
        }
        cout << "\n";
         */
    }
    vector <int> res;
    int c;
    for (int i = n; i >= 0; --i) {
        if (dp[i] != INT32_MAX) {
            c = dp[i];
            cout << i << "\n";
            while (c != INT32_MIN) {
                res.push_back(a[c]);
                c = pred[c];
            }
            break;
        }
    }
    reverse(res.begin(), res.end());
    for (int i : res) {
        cout << i << " ";
    }
}
