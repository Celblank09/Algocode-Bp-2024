#include <bits/stdc++.h>

using namespace std;

int get(int v, vector <int> &pred) {
    if (pred[v] == -1) {
        pred[v] = v;
    }
    if (pred[v] == v) {
        return v;
    }
    pred[v] = get(pred[v], pred);
    return pred[v];
}

void unite(int u, int v, vector <int> &sz, vector <int> &pred) {
    u = get(u, pred);
    v = get(v, pred);
    if (u == v) {
        return;
    }
    if (sz[u] > sz[v]) {
        swap(u, v);
    }
    pred[u] = v;
    sz[v] += sz[u];
}

struct operation {
    int type;
    int v;
    int u;
};

int main() {
    int n, m, k;
    string dop;
    cin >> n >> m >> k;
    vector <int> sz(n, 1);
    vector <int> pred(n, -1);
    vector <operation> oper(k, {0, 0, 0});
    vector <bool> res;
    for (int i = 0; i < m; ++i) {
        cin >> dop >> dop;
    }
    for (int i = 0; i < k; ++i) {
        cin >> dop >> oper[i].u >> oper[i].v;
        if (dop == "ask") {
            oper[i].type = 1;
        } else {
            oper[i].type = 2;
        }
    }
    reverse(oper.begin(), oper.end());
    for (operation i : oper) {
        if (i.type == 1) {
            if (get(i.u - 1, pred) == get(i.v - 1, pred)) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
        } else {
            unite(i.u - 1, i.v - 1, sz, pred);
        }
    }
    reverse(res.begin(), res.end());
    for (bool i : res) {
        if (i) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
