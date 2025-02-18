#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <vector <long long>> res(n + 1, vector <long long> (n + 1, 0));
    for (int y = 0; y <= n; ++y) {
        res[y][0] = 1;
    }
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= y; ++x) {
            res[y][x] = res[y - 1][x - 1] + res[y - 1][x];
        }
    }
    /*
    for (vector <long long> y : res) {
        for (long long x : y) {
            cout << x << " ";
        }
        cout << "\n";
    }
    */
    cout << res[n][k];
}
