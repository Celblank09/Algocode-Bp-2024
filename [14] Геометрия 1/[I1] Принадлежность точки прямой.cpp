#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    if (x * a + y * b == -c) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
