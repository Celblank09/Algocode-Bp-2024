#include <bits/stdc++.h>

using namespace std;

long long partition(vector<long long> &a, long long l, long long r) {
    long long x = a[(l + r) / 2];
    r--;
    while (l <= r) {
        while (a[l] < x) {
            ++l;
        }
        while (a[r] > x) {
            --r;
        }
        if (l >= r) {
            break;
        }
        swap(a[l++], a[r--]);
    }
    return l;
}

long long k_th_element(vector<long long> &a, long long l, long long r, long long k) {
    if (l + 1 == r) {
        return a[l];
    }
    long long pos = partition(a, l, r);
    long long cnt = pos - l;
    if (cnt >= k) {
        return k_th_element(a, l, pos, k);
    }
    return k_th_element(a, pos, r, k - cnt);
}

int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0);*/
    long long n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n, 0);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << k_th_element(a, 0, n, k);
}
