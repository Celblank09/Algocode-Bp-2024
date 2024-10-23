#include <bits/stdc++.h>

using namespace std;

int main() {
    double C, l = 0, r = 1e10, mid, epsilon = 1e-7;
    cin >> C;
    cout << setprecision(10) << fixed;
    while (abs(l - r) > epsilon) {
        mid = (l + r) / 2;
        if (mid * mid * mid * mid + mid == C) {
            cout << mid * mid;
            return 0;
        } else if (mid * mid * mid * mid + mid > C) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l * l;
}
