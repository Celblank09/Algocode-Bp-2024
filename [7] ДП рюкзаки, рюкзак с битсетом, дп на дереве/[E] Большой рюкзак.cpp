#include <bits/stdc++.h>

using namespace std;

bitset <6250000> a;

int main() {
    int n, w;
    cin >> n >> w;
    a[0] = true;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a |= (a << x);
    }
    if (a[w]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
