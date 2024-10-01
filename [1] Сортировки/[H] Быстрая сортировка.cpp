#include <bits/stdc++.h>

using namespace std;

long long partition(vector<long long> &a, long long l, long long r) {
    long long x = a[(l + r) / 2];
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
    return r;
}

void quick_sort(vector<long long> &a, long long l, long long r) {
    if (l >= r) {
        return;
    }
    long long k = partition(a, l, r);
    quick_sort(a, l, k);
    quick_sort(a, k + 1, r);
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
    quick_sort(a, 0, n - 1);
    for (long long i : a) {
        cout << i << " ";
    }
    return 0;
}