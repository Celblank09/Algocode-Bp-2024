#include <bits/stdc++.h>

using namespace std;

void BFS(long long x, long long y, long long n, vector <vector <long long>> &d, vector <pair <long long, long long>> &delta,
         vector <vector <pair <long long, long long>>> &pred) {
    long long nx, ny;
    d[y][x] = 0;
    queue <pair <long long, long long>> q;
    q.push({x, y});
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (pair <long long, long long> i : delta) {
            nx = x + i.first;
            ny = y + i.second;
            if (nx >= n || ny >= n || nx < 0 || ny < 0) {
                continue;
            }
            if (d[y][x] + 1 < d[ny][nx]) {
                d[ny][nx] = d[y][x] + 1;
                pred[ny][nx] = {y, x};
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    long long n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector <vector <long long>> d(n, vector <long long> (n, INT64_MAX));
    vector <pair <long long, long long>> delta = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
    vector <vector <pair <long long, long long>>> pred(n, vector <pair <long long, long long>> (n, pair <long long, long long> {-1, -1}));
    x1--;
    y1--;
    x2--;
    y2--;
    BFS(x1, y1, n, d, delta, pred);
    cout << d[y2][x2] << "\n";
    vector <pair <long long, long long>> res;
    while (x2 != -1) {
        res.push_back({x2 + 1, y2 + 1});
        long long y3 = pred[y2][x2].first;
        long long x3 = pred[y2][x2].second;
        x2 = x3;
        y2 = y3;
    }
    reverse(res.begin(), res.end());
    for (auto i : res) {
        cout << i.first << " " << i.second << "\n";
    }
}
