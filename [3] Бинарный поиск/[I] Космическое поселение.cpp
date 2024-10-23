#include <bits/stdc++.h>

using namespace std;

bool check(long long a, long long b, long long w, long long h, long long n) {
    return max((w / a) * (h / b), (h / a) * (w / b)) >= n;
}

int main() {
    long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    long long l = 0, r = 1e18 + 1, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(a + 2 * mid, b + 2 * mid, w, h, n)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;
}
