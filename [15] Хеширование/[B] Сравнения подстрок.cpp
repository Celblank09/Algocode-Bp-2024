#include <bits/stdc++.h>

using namespace std;

int sum(int a, int b, int MOD) {
    a += b;
    while (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int sub(int a, int b, int MOD) {
    a -= b;
    while (a < 0) {
        a += MOD;
    }
    return a;
}

long long mul(int a, int b, int MOD) {
    return ((long long)1 * a * b) % MOD;
}


struct Hasher {
    vector <int> hash;
    vector <int> powers;
    int MOD;
    int P;

    Hasher(const string &s, const int m, const int p) : hash(s.size() + 1), powers(s.size() + 1) {
        powers[0] = 1;
        hash[0] = 0;
        MOD = m;
        P = p;
        for (int i = 1; i <= s.size(); ++i) {
            powers[i] = mul(powers[i - 1], P, MOD);
            hash[i] = sum(mul(hash[i - 1], P, MOD), s[i - 1], MOD);
        }
    }

    int get(int l, int r) {
        return sub(hash[r], mul(hash[l], powers[r - l], MOD), MOD);
    }
};

int main() {
    int P = 31, MOD = 1'000'000'007;
    string s;
    cin >> s;
    Hasher h(s, MOD, P);
    int m, a, b, c, d;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c >> d;
        if (h.get(a - 1, b) == h.get(c - 1, d)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
