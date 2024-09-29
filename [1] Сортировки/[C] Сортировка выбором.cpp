#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<long long> &a, long long n) {
    for (long long i = 0; i < n - 1; ++i) {
        long long j = min_element(a.begin() + i, a.end()) - a.begin();
        swap(a[i], a[j]);
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
    selection_sort(a, n);
    for (long long i : a) {
        cout << i << " ";
    }
    return 0;
}
