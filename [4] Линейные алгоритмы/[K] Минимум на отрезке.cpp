#include <bits/stdc++.h>

using namespace std;

deque <pair <long long, long long>> d;
long long k;

void add(long long x, long long i) {
    while (!d.empty() && d.back().first > x) {
        d.pop_back();
    }
    d.push_back({x, i});
}

void pop(long long i) {
    if (d.front().second == i - k) {
        d.pop_front();
    }
}

long long get() {
    return d.front().first;
}

int main() {
    long long n, cur = 0;
    cin >> n >> k;
    vector <long long> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        add(a[i], i);
        pop(i);
        if (i >= k - 1) {
            cout << get() << "\n";
        }
    }
}
