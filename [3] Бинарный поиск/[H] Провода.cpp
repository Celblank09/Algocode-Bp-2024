#include <bits/stdc++.h>

using namespace std;

bool check(long long m, long long k, vector <long long> l) {
    long long s = 0;
    for (long long i : l) {
        s += i / m;
    }
    return s >= k;
}

int main() {
    long long n, k, sum = 0;
    cin >> n >> k;
    vector <long long> l(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        sum += l[i];
    }
    if (sum < k) {
        cout << 0;
        return 0;
    }
    long long le = 2, r = 1'000'000'000, mid;
    while (le + 1 < r) {
        mid = (le + r) / 2;
        if (check(mid, k, l)) {
            le = mid;
        } else {
            r = mid;
        }
    }
    cout << le;
}