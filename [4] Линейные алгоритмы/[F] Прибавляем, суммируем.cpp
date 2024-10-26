#include <bits/stdc++.h>

using namespace std;

unsigned int a, b;
unsigned int cur = 0;
unsigned int nextRand() {
    cur = cur * a + b;
    return cur >> 8;
}

int main() {
    long long l, r, add, two32 = pow(2, 32), azero = 0;
    long long m, q;
    cin >> m >> q;
    cin >> a >> b;
    vector <int> razn((long int)pow(2, 24) + 1, 0);
    for (long long i = 0; i < m; ++i) {
        add = nextRand();
        l = nextRand();
        r = nextRand();
        if (l > r) {
            swap(l, r);
        }
        if (l == 0) {
            azero += add;
        }
        razn[l] += add;
        razn[l] %= two32;
        razn[r + 1] -= add;
        razn[r + 1] %= two32;
    }
    vector <int> res1((long long)pow(2, 24), 0);
    res1[0] = azero;
    for (long long i = 1; i < (long long)pow(2, 24); ++i) {
        res1[i] = res1[i - 1] + razn[i];
        res1[i] %= two32;
    }
    vector <int> pref((long long)pow(2, 24) + 100, 0);
    for (long long i = 1; i < (long long)pow(2, 24) + 1; ++i) {
        pref[i] = pref[i - 1] + res1[i - 1];
        pref[i] %= two32;
    }
    long long res = 0;
    for (long long i = 0; i < q; ++i) {
        l = nextRand();
        r = nextRand();
        if (l > r) {
            swap(l, r);
        }
        res += pref[r + 1] - pref[l];
        res %= two32;
    }
    cout << (res % two32 + two32) % two32;
}
