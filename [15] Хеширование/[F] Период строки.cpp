#include <bits/stdc++.h>

using namespace std;

long long sum(long long a, long long b, long long MOD) {
    a += b;
    while (a >= MOD) {
        a -= MOD;
    }
    return a;
}

long long sub(long long a, long long b, long long MOD) {
    a -= b;
    while (a < 0) {
        a += MOD;
    }
    return a;
}

long long mul(long long a, long long b, long long MOD) {
    return (long long)(((__int128)1 * a * b) % MOD);
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

    int get(int l, int r) {
        return sub(hash[r], mul(hash[l], powers[r - l], MOD), MOD);
    }
};

int main() {
    long long P = 53, MOD = 29996224275833;
    string s;
    cin >> s;
    Hasher h(s, MOD, P);
    for (int i = 1; i < s.size(); ++i) {
        if (s.size() % i == 0 && h.get(0, s.size() - i) == h.get(i, s.size())) {
            cout << s.size() / i;
            return 0;
        }
    }
    cout << 1;
}
