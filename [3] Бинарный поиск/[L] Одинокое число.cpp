#include <bits/stdc++.h>

using namespace std;

long long ask(long long pos) {
    long long ans;
    cout << "? " << pos << endl;
    cout.flush();
    cin >> ans;
    return ans;
}

int main() {
    map <long long, long long> a;
    long long n;
    cin >> n;
    long long l = 1, r = n, m1, m2, ans1, ans2;
    while (l + 1 < r) {
        m1 = (r + l - 2) / 2;
        m2 = (r + l - 2) / 2 + 1;
        if (!a[m1]) {
            ans1 = ask(m1);
        } else {
            ans1 = a[m1];
        }
        if (!a[m2]) {
            ans2 = ask(m2);
        } else {
            ans2 = a[m2];
        }
        a[m1] = ans1;
        a[m2] = ans2;
        if (ans1 == ans2) {
            if ((r + l - 2) / 2 % 2 == 0) {
                r = m1 - 1;
            } else {
                l = m2 + 1;
            }
        } else {
            if ((r + l - 2) / 2 % 2 == 0) {
                l = m2;
            } else {
                r = m1;
            }
        }
    }
    if (a[l]) {
        cout << "! " << a[l] << endl;
        cout.flush();
    } else {
        a[l] = ask(l);
        cout << "! " << a[l] << endl;
        cout.flush();
    }
}
