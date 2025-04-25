#include <bits/stdc++.h>

using namespace std;

struct node {
    vector <int> g = vector <int> (2, -1);
    vector <int> c = vector <int> (2, 0);
    int c_term = 0;
    int up = -1;
};

int main() {
    int q, x, now, res, temp;
    node node_0;
    char type;
    cin >> q;
    vector <node> tree;
    tree.push_back(node_0);
    for (int i = 0; i < q; ++i) {
        cin >> type >> x;
        temp = x;
        vector <int> binar(32, 0);
        for (int j = 31; j >= 0; --j) {
            binar[j] = x % 2;
            x /= 2;
        }
        if (type == '+') {
            now = 0;
            for (int j = 0; j < 32; ++j) {
                if (tree[now].g[binar[j]] == -1) {
                    node_0.up = now;
                    tree.push_back(node_0);
                    tree[now].g[binar[j]] = tree.size() - 1;
                }
                tree[now].c[binar[j]]++;
                now = tree[now].g[binar[j]];
            }
        } else if (type == '-') {
            now = 0;
            for (int j = 0; j < 32; ++j) {
                tree[now].c[binar[j]]--;
                now = tree[now].g[binar[j]];
            }
        } else {
            res = 0;
            now = 0;
            if (tree[0].c[0] + tree[0].c[1] != 0) {
                for (int j = 0; j < 32; ++j) {
                    if (tree[now].c[1 - binar[j]] != 0) {
                        now = tree[now].g[1 - binar[j]];
                        res += pow(2, 31 - j);
                    } else {
                        now = tree[now].g[binar[j]];
                    }
                }
            }
            cout << max(res, temp) << "\n";
        }
    }
}
