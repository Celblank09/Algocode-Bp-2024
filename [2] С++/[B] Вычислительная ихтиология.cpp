#include <bits/stdc++.h>

using namespace std;

struct point {
    int t;
    int i;
    int n;
    bool operator<(const point &other) const {
        if (t == other.t) {
            return i < other.i;
        }
        return t < other.t;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, dop;
    set <point> a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> dop;
        a.insert({max(1, 1000 - dop), i, dop + 1});
    }
    int t1, i1, n1, t2, i2, n2;
    t1 = a.begin()->t;
    i1 = a.begin()->i;
    n1 = a.begin()->n;
    if (t1 < i1) {
        cout << t1;
        return 0;
    }
    while (true) {
        a.erase(a.begin());
        a.insert({t1 + max(1, 1000 - n1), i1, n1 + 1});
        t2 = a.begin()->t;
        i2 = a.begin()->i;
        n2 = a.begin()->n;
        if (abs(i2 - i1) > abs(t2 - t1)) {
            cout << t2;
            return 0;
        }
        t1 = t2;
        i1 = i2;
        n1 = n2;
    }
}
