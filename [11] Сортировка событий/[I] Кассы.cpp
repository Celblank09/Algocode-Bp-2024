#include <bits/stdc++.h>

using namespace std;

struct event {
    int t;
    int type;
    bool operator<(event const &other) const {
        if (t == other.t) {
            return type < other.type;
        }
        return t < other.t;
    }
};

int main() {
    int n, h1, m1, s1, h2, m2, s2, cur = 0, all_open, res = 0;
    cin >> n;
    vector <event> events;
    for (int i = 0; i < n; ++i) {
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        s1 = 3600 * h1 + 60 * m1 + s1;
        s2 = 3600 * h2 + 60 * m2 + s2;
        if (s1 < s2) {
            events.push_back({s1, 1});
            events.push_back({s2, -1});
        } else {
            events.push_back({s1, 1});
            events.push_back({24 * 3600, -1});
            events.push_back({0, 1});
            events.push_back({s2, -1});
        }
    }
    sort(events.begin(), events.end());
    for (event i : events) {
        if (i.type < 0 && cur == n) {
            res += i.t - all_open;
        }
        cur += i.type;
        if (cur == n) {
            all_open = i.t;
        }
    }
    cout << res;
}
