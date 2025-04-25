#include <bits/stdc++.h>

using namespace std;

struct node {
    map <char, int> g;
    map <char, int> c;
    int c_term = 0;
    int up = -1;
};

int main() {
    int q, now, res = 0, type, k;
    bool flag;
    node node_0;
    string x, res_s;
    cin >> q;
    vector <node> tree;
    tree.push_back(node_0);
    for (int i = 0; i < q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            now = 0;
            for (char ch : x) {
                if (tree[now].g[ch] == 0) {
                    node_0.up = now;
                    tree.push_back(node_0);
                    tree[now].g[ch] = tree.size() - 1;
                }
                tree[now].c[ch]++;
                now = tree[now].g[ch];
            }
            tree[now].c_term = 1;
        } else {
            cin >> k;
            res = 0;
            now = 0;
            while (res != k) {
                flag = true;
                for (char j : "abcdefghijklmnopqrstuvwxyz") {
                    if (res + tree[now].c[j] < k) {
                        res += tree[now].c[j];
                    } else {
                        flag = false;
                        now = tree[now].g[j];
                        cout << j;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            while (tree[now].c_term == 0) {
                for (char j : "abcdefghijklmnopqrstuvwxyz") {
                    if (tree[now].g[j] != 0) {
                        cout << j;
                        now = tree[now].g[j];
                        break;
                    }
                }
            }
            cout << "\n";
        }
    }
}
