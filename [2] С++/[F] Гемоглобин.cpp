#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <long long> base;
    vector <long long> pref = {0};
    string operation;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> operation;
        if (operation[0] == '-') {
            cout << base[base.size() - 1] << "\n";
            pref.pop_back();
            base.pop_back();
        } else if (operation[0] == '+') {
            long long n = stoll(operation.substr(1, operation.size() - 1));
            base.push_back(n);
            pref.push_back(pref[pref.size() - 1] + n);
        } else if (operation[0] == '?') {
            long long k = stoll(operation.substr(1, operation.size() - 1));
            cout << pref[pref.size() - 1] - pref[pref.size() - 1 - k] << "\n";
        }
    }
}