#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector <long long> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <pair <long long, long long>> m;
    m.push_back({INT64_MIN, -1});
    vector <long long> res(n, -1);
    for (int i = 0; i < n; ++i) {
        while (m.back().first > a[i]) {
            res[m.back().second] = i;
            m.pop_back();
        }
        m.push_back({a[i], i});
    }
    for (long long i : res) {
        cout << i << " ";
    }
}
