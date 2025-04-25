#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector <int> p(s.size(), 0);
    for (int i = 1; i < s.size(); ++i) {
        int k = p[i - 1];
        while (k > 0 && s[i] != s[k]) {
            k = p[k - 1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        p[i] = k;
    }
    for (int i : p) {
        cout << i << " ";
    }
}
