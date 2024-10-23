#include <bits/stdc++.h>

using namespace std;

int main() {
    long long w, h, n;
    cin >> w >> h >> n;
    long long l = max(w, h), r = n * max(w, h), m;
    while (l + 1 < r) {
        m = (l + r) / 2;
        if ((m / w) * (m / h) >= n) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;
}
