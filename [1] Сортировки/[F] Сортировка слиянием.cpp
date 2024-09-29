#include <bits/stdc++.h>

using namespace std;

vector <long long> merge(vector <long long> &a, vector <long long> &b) {
    vector <long long> c(a.size() + b.size(), 0);
    long long l_a = 0, l_b = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (l_a < a.size() && l_b < b.size()) {
            if (a[l_a] <= b[l_b]) {
                c[i] = a[l_a];
                l_a++;
            } else {
                c[i] = b[l_b];
                l_b++;
            }
        } else if (l_a == a.size()) {
            c[i] = b[l_b];
            l_b++;
        } else {
            c[i] = a[l_a];
            l_a++;
        }
    }
    return c;
}

vector <long long> merge_sort(vector<long long> a, long long l, long long r) {
    if (a.size() <= 1) {
        return a;
    }
    long long m = (l + r) / 2;
    vector <long long> L;
    vector <long long> R;
    for (long long i = l; i < r; ++i) {
        if (i < m) {
            L.push_back(a[i]);
        } else {
            R.push_back(a[i]);
        }
    }
    L = merge_sort(L, l, m);
    R = merge_sort(R, 0, r - m);
    return merge(L, R);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> a(n, 0);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a = merge_sort(a, 0, n);
    for (long long i : a) {
        cout << i << " ";
    }
    return 0;
}
