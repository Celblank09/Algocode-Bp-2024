#include <bits/stdc++.h>

using namespace std;

struct Segment {
    int length;
    int l;
    int r;
    bool is_free;
    bool operator<(const Segment &other) const {
        return l < other.l;
    }
};

int main() {
    int n, m, t;
    cin >> n >> m;
    set <Segment> a;
    a.insert({n, 1, n, true});
    map <int, set <Segment>> b;
    b[n] = {{n, 1, n, true}};
    for (int i = 0; i < m; ++i) {
        cin >> t;
        if (b.lower_bound(t)) {

        }
    }
}