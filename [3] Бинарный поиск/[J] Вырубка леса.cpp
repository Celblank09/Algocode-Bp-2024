#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, k, b, m, x;
    cin >> a >> k >> b >> m >> x;
    long long l = 1, r = 2 * x, mid;
    if (k != 1 && a >= x) {
        cout << 1;
        return 0;
    }
    if (m != 1 && b >= x) {
        cout << 1;
        return 0;
    }
    if (k != 1 && m != 1 && a + b >= x) {
        cout << 1;
        return 0;
    }
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if ((mid - mid / k) * a >= x || (mid - mid / m) * b >= x || (mid - mid / k) * a + (mid - mid / m) * b >= x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
}
