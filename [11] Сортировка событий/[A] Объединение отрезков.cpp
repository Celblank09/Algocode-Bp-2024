#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <pair <int, int>> segments(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }
    sort(segments.begin(), segments.end());
    vector <pair <int, int>> res;
    for (int i = 0; i < n; ++i) {
        if (res.empty() || segments[i].first > res[res.size() - 1].second) {
            res.push_back({segments[i].first, segments[i].second});
        }
        res[res.size() - 1].second = max(res[res.size() - 1].second, segments[i].second);
    }
    cout << res.size() << "\n";
    for (auto i : res) {
        cout << i.first << " " << i.second << "\n";
    }
}
