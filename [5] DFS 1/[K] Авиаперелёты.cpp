#include <bits/stdc++.h>

using namespace std;

void dfs(long long vershina, vector <long long> &used, vector <vector <long long>> &a, long long W) {
    used[vershina] = 1;
    for (long long i = 0; i < a[vershina].size(); ++i) {
        if (used[i] == 0 && a[i][vershina] <= W) {
            dfs(i, used, a, W);
        }
    }
}

int main() {
    long long n, first, first1 = INT64_MAX;
    cin >> n;
    set <long long> W;
    vector <vector <long long>> a(n, vector <long long> (n, 0));
    for (int i = 0; i < n; ++i) {
        first1 = INT64_MAX;
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            first1 = min(first1, a[i][j]);
            W.insert(a[i][j]);
        }
        first = max(first1, first);
    }
    vector <long long> used(n, 0);
    bool flag;
    long long l = -1, r = 1000000000, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        flag = true;
        used = vector<long long>(n, 0);
        dfs(0, used, a, mid);
        for (long long j : used) {
            if (j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
}
