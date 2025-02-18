#include <bits/stdc++.h>

using namespace std;

mt19937 rng(120);

int main() {
    map <int, long long> r;
    int n, m, res = 0;
    cin >> n;
    vector <int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!r[a[i]]) {
            r[a[i]] = rng() % 1'000'000'007;
        }
    }
    cin >> m;
    vector <int> b(m, 0);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        if (!r[b[i]]) {
            r[b[i]] = rng() % 1'000'000'007;
        }
    }
    /*for (auto i : r) {
        cout << i.first << " " << i.second << "\n";
    }*/
    long long h;
    set <long long> Hashes;
    for (int k = 1; k <= min(n, m); ++k) {
        h = 0;
        Hashes.clear();
        for (int i = 0; i < k; ++i) {
            h += r[a[i]];
        }
        Hashes.insert(h);
        for (int i = k; i < n; ++i) {
            h -= r[a[i - k]];
            h += r[a[i]];
            Hashes.insert(h);
        }
        h = 0;
        for (int i = 0; i < k; ++i) {
            h += r[b[i]];
        }
        if (*Hashes.lower_bound(h) == h) {
            res = max(res, k);
        }
        for (int i = k; i < n; ++i) {
            h -= r[b[i - k]];
            h += r[b[i]];
            if (*Hashes.lower_bound(h) == h) {
                res = max(res, k);
            }
        }
    }
    cout << res;
}
