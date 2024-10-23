#include <bits/stdc++.h>

using namespace std;

struct Layer {
    int number;
    int last = 0;
    bool operator< (const Layer &other) {
        return last < other.last;
    }
};

struct Block {
    int first;
    int last;
    int i;
    bool operator< (const Block &other) const {
        return first < other.first;
    }
};

int main() {
    int n, w, a1, w1;
    cin >> n >> w;
    set <Block> a;
    for (int i = 0; i < n; ++i) {
        cin >> a1 >> w1;
        a.insert({a1, a1 + w1, i});
    }
    set <Layer> b;
    vector <vector <int>> res;
    for (auto i : a) {
        int dop = b.lower_bound();
    }
}