#include <bits/stdc++.h>

using namespace std;

long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return g;
}

int main() {
    long long a, b, c, x1, y1, g, x, y;
    cin >> a >> b >> c;
    clock_t start = clock();
    g = ext_gcd(a, b, x1, y1);
    if (c % g != 0) {
        cout << "Impossible";
        return 0;
    }
    x = x1 * c / g;
    y = y1 * c / g;
    while (x >= 0) {
        x -= b / g;
        y += a / g;
    }
    while (x < 0) {
        x += b / g;
        y -= a / g;
    }
    cout << x << " " << y;
}
