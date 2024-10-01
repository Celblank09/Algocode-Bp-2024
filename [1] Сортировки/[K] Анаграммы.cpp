#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    map <char, int> a1, b1;
    for (char i : a) {
        if (a1[i]) {
            a1[i]++;
        } else {
            a1[i] = 1;
        }
    }
    for (char i : b) {
        if (b1[i]) {
            b1[i]++;
        } else {
            b1[i] = 1;
        }
    }
    for (char i : "qwertyuiopasdfghjklzxcvbnm1234567890") {
        if (a1[i] != b1[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
