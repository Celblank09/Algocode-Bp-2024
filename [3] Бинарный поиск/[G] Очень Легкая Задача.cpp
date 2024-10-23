#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, x, y, res, l = 0, r = 2 * 1e9, m;
    cin >> n >> x >> y;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        cout << min(x, y);
        return 0;
    }
    res = min(x, y);
    n--;
    while (l + 1 < r) {
        m = (l + r) / 2;
        if (m / x + m / y >= n) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << res + r;
}
