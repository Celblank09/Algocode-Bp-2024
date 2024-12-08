#include <bits/stdc++.h>

using namespace std;

bitset <6250000> a;

int main() {
    int n, w = 0;
    cin >> n;
    a[0] = true;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        w += x;
        a |= (a << x);
    }
    if (w % 2 == 1) {
        cout << "NO";
        return 0;
    }
    if (a[w / 2]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
