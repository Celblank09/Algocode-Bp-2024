#include <bits/stdc++.h>

using namespace std;

int main() {
    clock_t start;
    int a, b, res = 0;
    cin >> a >> b;
    start = clock();
    a -= b;
    if (a == 0) {
        cout << "infinity";
        return 0;
    }
    set <int> factors;
    for (int i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            factors.insert(i);
            factors.insert(a / i);
        }
    }
    auto i = factors.upper_bound(b);
    while (i != factors.end()) {
        res++;
        i = next(i);
    }
    cout << res << "\n";
}