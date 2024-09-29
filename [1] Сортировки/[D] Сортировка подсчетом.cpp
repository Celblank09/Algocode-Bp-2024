#include <bits/stdc++.h>

using namespace std;

void counting_sort(vector<long long> &a) {
    vector <long long> c(2 * 10000 + 1, 0);
    for (long long i : a) {
        c[i + 10000]++;
    }
    long long pos = 0;
    for (long long i = 0; i < 2 * 10000 + 1; ++i) {
        for (long long j = 0; j < c[i]; ++j) {
            a[pos + j] = i - 10000;
        }
        pos += c[i];
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
    counting_sort(a);
    for (long long i : a) {
        cout << i << " ";
    }
    return 0;
}
