#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<long long> &a, long long n) {
    for (long long i = 1; i < n; ++i) {
        long long j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]);
            j--;
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
    insertion_sort(a, n);
    for (long long i : a) {
        cout << i << " ";
    }
    return 0;
}
