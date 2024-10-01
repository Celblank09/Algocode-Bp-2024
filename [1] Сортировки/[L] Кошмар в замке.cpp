#include <bits/stdc++.h>

using namespace std;

void insertion_sort(string &a, long long n, map <char, int> &w) {
    for (long long i = 1; i < n; ++i) {
        long long j = i;
        while (j > 0 && w[a[j]] > w[a[j - 1]]) {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}

int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0);*/
    string a;
    cin >> a;
    map <char, int> a1;
    for (char i : a) {
        if (a1[i]) {
            a1[i]++;
        } else {
            a1[i] = 1;
        }
    }
    map <char, int> w;
    for (int i = 0; i < 26; ++i) {
        cin >> w[((string)"abcdefghijklmnopqrstuvwxyz")[i]];
    }
    string sorted_alp = "abcdefghijklmnopqrstuvwxyz";
    insertion_sort(sorted_alp, sorted_alp.size(), w);
    string res = "";
    long long b = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += " ";
    }
    for (char i : sorted_alp) {
        if (a1[i] >= 2) {
            res[b] = i;
            res[res.size() - 1 - b] = i;
            b++;
            a1[i] -= 2;
        }
    }
    for (char i : sorted_alp) {
        while (a1[i] >= 1) {
            res[b] = i;
            b++;
            a1[i]--;
        }
    }
    cout << res;
}
