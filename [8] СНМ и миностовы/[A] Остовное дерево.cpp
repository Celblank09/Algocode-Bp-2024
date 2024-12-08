#include <bits/stdc++.h>

using namespace std;

void unit(long long x, long long y, vector <long long> &head, vector <long long> &count, vector <long long> &next, vector <long long> &tail) {
    x = head[x];
    y = head[y];
    if (x == y) {
        return;
    }
    if (count[x] > count[y]) {
        swap(x, y);
    }
    long long i = head[x];
    while (i != -1) {
        head[i] = y;
        i = next[i];
    }
    next[tail[y]] = head[x];
    tail[y] = tail[x];
    count[y] += count[x];
}

int main() {
    long long n, m;
    cin >> n >> m;
}