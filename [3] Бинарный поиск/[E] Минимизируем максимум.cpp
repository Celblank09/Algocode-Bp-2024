#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, l, x, y, left, right, mid, q;
    cin >> n >> m >> l;
    vector <vector <long long>> a(n, vector <long long> (l, 0));
    vector <vector <long long>> b(m, vector <long long> (l, 0));
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < l; ++j) {
            cin >> a[i][j];
        }
    }
    for (long long i = 0; i < m; ++i) {
        for (long long j = 0; j < l; ++j) {
            cin >> b[i][j];
        }
    }
    cin >> q;
    for (long long i = 0; i < q; ++i) {
        cin >> x >> y;
        left = 0;
        right = l - 1;
        x--;
        y--;
        if (a[x][0] > b[y][0]) {
            cout << 1 << "\n";
            continue;
        }
        if (b[y][l - 1] > a[x][l - 1]) {
            cout << l << "\n";
            continue;
        }
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (a[x][mid] >= b[y][mid]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (max(a[x][left], b[y][left]) < max(a[x][right], b[y][right])) {
            cout << left + 1 << "\n";
        } else {
            cout << right + 1 << "\n";
        }
    }
}
