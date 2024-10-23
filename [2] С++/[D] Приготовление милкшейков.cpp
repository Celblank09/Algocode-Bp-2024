#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string, long long> ingredients;
    long long t, q, a, n;
    bool flag = false;
    map<string, long long> cocktail;
    string name1, name2;
    cin >> q;
    for (long long i = 0; i < q; ++i) {
        cin >> t;
        if (t == 1) {
            flag = false;
            cin >> name1;
            cin >> n;
            for (long long j = 0; j < n; ++j) {
                cin >> a >> name2;
                cocktail[name2] = a;
                if (ingredients[name2] < a) {
                    flag = true;
                }
            }
            if (flag) {
                cout << ":(\n";
                cocktail.clear();
            } else {
                for (pair<string, long long> j : cocktail) {
                    ingredients[j.first] -= j.second;
                }
                cocktail.clear();
                cout << "Milkshake " << name1 << " is ready\n";
            }
        } else {
            cin >> a >> name1;
            ingredients[name1] += a;
            cout << name1 << ": " << ingredients[name1] << "\n";
        }
    }
}
