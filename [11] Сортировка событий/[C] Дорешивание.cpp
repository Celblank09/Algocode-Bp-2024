#include <bits/stdc++.h>

using namespace std;

struct point {
    int x;
    int type;
    int id;
    bool operator< (point const &other) const {
        if (x == other.x) {
            return type < other.type;
        }
        return x < other.x;
    }
};

int main() {
    int n, l, r, cur;
    cin >> n;
    vector <point> ls;
    vector <point> rs;
    vector <int> res(n, n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        ls.push_back({l, -1, i});
        ls.push_back({r, 1, i});
        rs.push_back({-l, 1, i});
        rs.push_back({-r, -1, i});
    }
    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end());
    cur = 0;
    for (point i : ls) {
        if (i.type == -1) {
            res[i.id] -= cur;
        } else {
            cur++;
        }
    }
    cur = 0;
    for (point i : rs) {
        if (i.type == -1) {
            res[i.id] -= cur;
        } else {
            cur++;
        }
    }
    for (int i : res) {
        cout << i << "\n";
    }
}
