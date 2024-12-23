#include <bits/stdc++.h>

using namespace std;

void BFS(long long v, vector <long long> &d, vector <long long> &pred) {
    d[v] = 0;
    queue <long long> q;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        long long u;
        if (v % 10 != 1) {
            u = v - 1;
            if (d[v] + 1 < d[u]) {
                d[u] = d[v] + 1;
                pred[u] = v;
                q.push(u);
            }
        }
        if (v + 1000 <= 9999) {
            u = v + 1000;
            if (d[v] + 1 < d[u]) {
                d[u] = d[v] + 1;
                pred[u] = v;
                q.push(u);
            }
        }
        u = v % 1000 * 10 + v / 1000;
        if (d[v] + 1 < d[u]) {
            d[u] = d[v] + 1;
            pred[u] = v;
            q.push(u);
        }
        u = v / 10 + v % 10 * 1000;
        if (d[v] + 1 < d[u]) {
            d[u] = d[v] + 1;
            pred[u] = v;
            q.push(u);
        }
    }
}

int main() {
    long long v, u;
    cin >> v >> u;
    vector <long long> d(10000, INT64_MAX);
    vector <long long> pred(10000, -1);
    BFS(v, d, pred);
    vector <long long> res;
    while (u != -1) {
        res.push_back(u);
        u = pred[u];
    }
    reverse(res.begin(), res.end());
    for (auto i : res) {
        cout << i << "\n";
    }
}
