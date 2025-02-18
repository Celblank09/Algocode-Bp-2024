#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, l, r;
    cin >> n >> m;
    vector <pair <int, int>> segments(n * 2 + m, {0, 0}); // 0 - open, 1 - point, 2 - close
    map <int, int> transfer;
    vector <int> points(m, 0);
    vector <int> true_res;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        segments[2 * i] = {min(l, r), 0};
        segments[2 * i + 1] = {max(l, r), 2};
    }
    for (int i = 0; i < m; ++i) {
        cin >> l;
        segments[2 * n + i] = {l, 1};
        points[i] = l;
    }
    sort(segments.begin(), segments.end());
    vector <int> res(m, 0);
    int cur = 0, cur_i = 0;
    for (auto i : segments) {
        if (i.second == 0) {
            cur++;
        } else if (i.second == 1) {
            res[cur_i] = cur;
            transfer[i.first] = cur_i;
            cur_i++;
        } else {
            cur--;
        }
    }
    for (int i : points) {
        true_res.push_back(res[transfer[i]]);
    }
    for (int i : true_res) {
        cout << i << " ";
    }
}
