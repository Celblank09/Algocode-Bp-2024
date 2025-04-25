#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector <int> n(s.size(), 0);
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (i < r) {
            n[i] = min(n[i - l], r - i);
        }
        while (i + n[i] < s.size() && s[i + n[i]] == s[n[i]]) {
            n[i]++;
        }
        if (i + n[i] > r) {
            l = i;
            r = i + n[i];
        }
    }
    n[0] = s.size();
    for (int i : n) {
        cout << i << " ";
    }
}
