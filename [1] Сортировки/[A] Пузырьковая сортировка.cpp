#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<long long> &a, long long n) {
    for (long long i = n - 1; i >= 0; --i) {
        for (long long j = 1; j <= i; ++j) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
        }
    }
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
    bubble_sort(a, n);
    for (long long i : a) {
        cout << i << " ";
    }
    return 0;
}
