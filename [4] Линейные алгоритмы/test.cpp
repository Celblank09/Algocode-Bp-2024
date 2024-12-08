#include <bits/stdc++.h>

using namespace std;

unsigned int a = 0, b = 0;
unsigned int cur = 0;
unsigned int nextRand() {
    cur = cur * a + b;
    return cur >> 8;
}

int main() {
    long long l, r, add, two32 = (long long)pow(2, 32), azero = 0;
    long long m, q;
    cin >> m >> q;
    cin >> a >> b;
    vector <long long> razn((long long)pow(2, 24) + 2, 0);
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
        razn[r + 1] -= add;
    }
    vector <long long> res1((long long)pow(2, 24) + 1, 0);
    res1[0] = azero;
    for (long long i = 1; i < res1.size(); ++i) {
        res1[i] = res1[i - 1] + razn[i];
    }
    vector <long long> pref((long long)pow(2, 24) + 2, 0);
    for (long long i = 1; i < res1.size(); ++i) {
        pref[i] = pref[i - 1] + res1[i - 1];
    }
    long long res = 0;
    for (long long i = 0; i < q; ++i) {
        l = nextRand();
        r = nextRand();
        if (l > r) {
            swap(l, r);
        }
        res += pref[r + 1] - pref[l];
    }
    cout << res % two32;
}
