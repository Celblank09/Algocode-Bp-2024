#include <bits/stdc++.h>

using namespace std;

int ask(long long a) {
    cout << "? " << a << endl;
    cout.flush();
    int dop;
    cin >> dop;
    return dop;
}

int main() {
    long long n;
    cin >> n;
    long long l = 1, r = n, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (ask(mid) == 1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << "! " << l;
    exit(0);
}
