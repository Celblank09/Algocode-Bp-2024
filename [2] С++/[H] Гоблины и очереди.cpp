#include <bits/stdc++.h>

using namespace std;

int main() {
    deque <int> start;
    deque <int> end;
    int n, number;
    string type;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> type;
        if (type == "*") {
            cin >> number;
            start.push_back(number);
        } else if (type == "+") {
            cin >> number;
            end.push_back(number);
        } else if (type == "-") {
            cout << start.front() << "\n";
            start.pop_front();
        }
        while (start.size() > end.size() + 1) {
            auto dop = start.back();
            start.pop_back();
            end.push_front(dop);
        }
        while (start.size() < end.size()) {
            auto dop = end.front();
            end.pop_front();
            start.push_back(dop);
        }
    }
}
