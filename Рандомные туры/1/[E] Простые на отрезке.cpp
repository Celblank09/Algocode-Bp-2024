#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    vector <bool> is_prime(2 * b + 1, true);
    vector <int> primes_count(2 * b + 1, 0);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= 2 * b; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 2 * b; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 1; i <= 2 * b; ++i) {
        primes_count[i] = primes_count[i - 1] + is_prime[i];
    }
    if (primes_count[b] - primes_count[a - 1] < k) {
        cout << -1;
        return 0;
    }
    int l = 0, r = b - a + 2, m;
    bool flag;
    while (l + 1 != r) {
        m = (l + r) / 2;
        flag = true;
        for (int i = a; i <= b - m + 1; ++i) {
            if (primes_count[i + m - 1] - primes_count[i - 1] < k) {
                flag = false;
            }
        }
        if (flag) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;
}