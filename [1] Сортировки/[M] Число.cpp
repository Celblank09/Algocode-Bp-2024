#include <bits/stdc++.h>

using namespace std;

bool cmp(string A, string B) {
    return A + B > B + A;
}

int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0);*/
    vector <string> a;
    string dop;
    while (cin >> dop) {
        a.push_back(dop);
    }
    sort(a.begin(), a.end(), cmp);
    for (string i : a) {
        cout << i;
    }
}
