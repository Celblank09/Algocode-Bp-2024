#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a1, a2;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (n, 0));
    for (int i = 0; i < m; ++i) {
        cin >> a1 >> a2;
        a[a1 - 1][a2 - 1] = 1;
    }
    for (vector <int> i : a) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}
