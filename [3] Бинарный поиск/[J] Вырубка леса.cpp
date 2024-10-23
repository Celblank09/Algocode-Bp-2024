#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, k, b, m, x;
    cin >> a >> k >> b >> m >> x;
    long long l = 1, r = 1'000'000'000, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (mid * a - (mid / k) * a + (mid * b) - mid / m * b >= x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
}
