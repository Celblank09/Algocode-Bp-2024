#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s >> s;
    vector <long long> dp(s.size() + 1, INT64_MAX);
    vector <long long> a;
    map <char, long long> last;
    dp[1] = 1;
    last[s[0]] = 1;
    for (long long i = 2; i <= s.size(); ++i) {
        last[s[i - 1]] = i;
        a.clear();
        for (auto j : last) {
            a.push_back(j.second);
            //cout << j.second << " ";
        }
        //cout << "\n";
        sort(a.rbegin(), a.rend());
        dp[i] = a.size() * a.size();
        for (long long j = 0; j < a.size(); ++j) {
            dp[i] = min(dp[i], dp[a[j]] + j * j);
        }
    }
    cout << dp[s.size()];
    /*
    for (long long i : dp) {
        cout << i << " ";
    }
    */
}
