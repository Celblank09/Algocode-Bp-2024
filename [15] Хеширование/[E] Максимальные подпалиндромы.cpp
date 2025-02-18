#include <bits/stdc++.h>

using namespace std;

long long sum(long long a, long long b, long long MOD) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

long long sub(long long a, long long b, long long MOD) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
    return a;
}

long long mul(long long a, long long b, long long MOD) {
    return (a * b) % MOD;
}


struct Hasher {
    vector <long long> hash;
    vector <long long> powers;
    long long MOD;
    long long P;

    Hasher(const string &s, const long long m, const long long p) : hash(s.size() + 1), powers(s.size() + 1) {
        powers[0] = 1;
        hash[0] = 0;
        MOD = m;
        P = p;
        for (int i = 1; i <= s.size(); ++i) {
            powers[i] = mul(powers[i - 1], P, MOD);
            hash[i] = sum(mul(hash[i - 1], P, MOD), s[i - 1], MOD);
        }
    }

    long long get(int l, int r) {
        return sub(hash[r], mul(hash[l], powers[r - l], MOD), MOD);
    }
};

int main() {
    int P = 257, MOD = 1'000'000'007;
    string s;
    cin >> s;
    Hasher h(s, MOD, P);
    reverse(s.begin(), s.end());
    Hasher r_h(s, MOD, P);
    for (int i = 0; i < s.size(); ++i) {
        int l = 0, r = s.size() + 1, m;
        while (l + 1 != r) {
            m = (l + r) / 2;
            if (i + m >= s.size() || i - m < 0 || s.size() - (i + m) - 1 < 0 || s.size() - (i - m) > s.size() ||
                    s.size() - (i + m) - 1 > s.size() - (i - m)) {
                r = m;
                continue;
            }
            if (h.get(i - m, i + m + 1) == r_h.get(s.size() - (i + m) - 1, s.size() - (i - m))) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << 2 * l + 1 << " ";
    }
}
