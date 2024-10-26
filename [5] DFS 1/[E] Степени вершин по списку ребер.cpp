#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a1, a2;
    cin >> n >> m;
    vector <int> a(n, 0);
    for (int i = 0; i < m; ++i) {
        cin >> a1 >> a2;
        a[a1 - 1]++;
        a[a2 - 1]++;
    }
    for (int i : a) {
        cout << i << " ";
    }
    cout << "\n";
}
