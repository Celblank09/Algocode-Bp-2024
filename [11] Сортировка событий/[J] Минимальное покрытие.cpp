#include <bits/stdc++.h>

using namespace std;

struct segment {
    int l;
    int r;
    bool operator<(const segment &other) const {
        return l < other.l;
    }
};

int main() {
    int m, l, r, M_last = 0, last = 0;
    bool flag;
    cin >> m;
    cin >> l >> r;
    vector <segment> segments;
    vector <segment> res;
    while (l != 0 || r != 0) {
        segments.push_back({l, r});
        cin >> l >> r;
    }
    sort(segments.begin(), segments.end());
    set<pair <int, int>> can;
    while (M_last < m) {
        if (!can.empty() && prev(can.end()) -> first > M_last) {
            M_last = prev(can.end()) -> first;
            res.push_back(segments[prev(can.end()) -> second]);
        }
        if (M_last >= m) {
            break;
        }
        flag = false;
        while (last < segments.size() && segments[last].l <= M_last) {
            flag = true;
            can.insert({segments[last].r, last});
            last++;
        }
        if (!flag) {
            cout << "No solution";
            return 0;
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (segment i : res) {
        cout << i.l << " " << i.r << "\n";
    }
}
