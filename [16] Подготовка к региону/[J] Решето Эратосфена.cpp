#include <bits/stdc++.h>

using namespace std;

int main() {
    bool flag;
    int a, b;
    cin >> a >> b;
    vector <bool> res(b + 1, true);
    vector <int> p;
    res[1] = false;
    for (int i = 2; i <= b; ++i) {
        flag = true;
        for (int j : p) {
            if (i % j == 0) {
                flag = false;
                break;
            }
            if (j * j > i) {
                break;
            }
        }
        if (!flag) {
            res[i] = false;
        } else {
            p.push_back(i);
        }
    }
    for (int i = a; i <= b; ++i) {
        if (res[i]) {
            cout << i << " ";
        }
    }
}
