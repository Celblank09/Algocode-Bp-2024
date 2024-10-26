#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x, a = 1, b = 1, last;
    cin >> x;
    for (int i = 0; i < x; ++i) {
        if (a * a == b * b * b) {
            last = a * a;
            a++;
            b++;
        } else if (a * a < b * b * b) {
            last = a * a;
            a++;
        } else {
            last = b * b * b;
            b++;
        }
    }
    cout << last;
}
