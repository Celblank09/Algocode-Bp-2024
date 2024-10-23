#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, dop;
    cin >> n;
    vector <int> a;
    vector <bool> res;
    for (int i = 0; i < n; ++i) {
        cin >> dop;
        a.push_back(dop);
    }
    reverse(a.begin(), a.end());
    vector <int> dead_end;
    for (int i = 1; i <= n; ++i) {
        if (!dead_end.empty() && dead_end.back() == i) {
            dead_end.pop_back();
            res.push_back(true);
            continue;
        }
        while (!a.empty() && (dead_end.empty() || dead_end.back() != i)) {
            dead_end.push_back(a.back());
            a.pop_back();
            res.push_back(false);
        }
        if (dead_end.back() != i) {
            cout << 0;
            return 0;
        }
        res.push_back(true);
        dead_end.pop_back();
    }
    cout << res.size() << "\n";
    for (bool i : res) {
        if (i) {
            cout << "2 1\n";
        } else {
            cout << "1 1\n";
        }
    }
}
