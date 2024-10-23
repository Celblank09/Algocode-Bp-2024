#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, x1, y1, x2, y2, type;
    cin >> n >> q;
    vector <int> x(n + 1, 0);
    vector <int> y(n + 1, 0);
    set <int> hor, vert;
    for (int i = 0; i <= n + 1; ++i) {
        hor.insert(i);
        vert.insert(i);
    }
    for (int i = 0; i < q; i++) {
        cin >> type;
        cin >> x1 >> y1;
        if (type == 1) {
            x[x1]++;
            y[y1]++;
            hor.erase(y1);
            vert.erase(x1);
        } else if (type == 2) {
            x[x1]--;
            y[y1]--;
            if (y[y1] == 0) {
                hor.insert(y1);
            }
            if (x[x1] == 0) {
                vert.insert(x1);
            }
        } else {
            cin >> x2 >> y2;
            if (x2 < *vert.lower_bound(x1) || y2 < *hor.lower_bound(y1)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}
