#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map <long long, set <int>> list_set_of;
    map <int, set <long long>> list_set;
    string type;
    long long n, e;
    int m, k, s;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> type;
        if (type == "ADD") {
            cin >> e >> s;
            list_set_of[e].insert(s);
            list_set[s].insert(e);
        } else if (type == "DELETE") {
            cin >> e >> s;
            list_set_of[e].erase(s);
            list_set[s].erase(e);
        } else if (type == "CLEAR") {
            cin >> s;
            for (auto j : list_set[s]) {
                list_set_of[j].erase(s);
            }
            list_set[s].clear();
        } else if (type == "LISTSET") {
            cin >> s;
            if (list_set[s].empty()) {
                cout << "-1\n";
                continue;
            }
            for (auto j : list_set[s]) {
                cout << j << " ";
            }
            cout << "\n";
        } else if (type == "LISTSETSOF") {
            cin >> e;
            if (list_set_of[e].empty()) {
                cout << "-1\n";
                continue;
            }
            for (auto j : list_set_of[e]) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
}
