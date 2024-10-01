#include <bits/stdc++.h>

using namespace std;


struct Person {
    long long id;
    long long res;
};

bool cmp(Person A, Person B) {
    if (A.res == B.res) {
        return A.id < B.id;
    }
    return A.res > B.res;
}

vector <Person> merge(vector <Person> &a, vector <Person> &b) {
    vector <Person> c(a.size() + b.size(), {0, 0});
    long long l_a = 0, l_b = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (l_a < a.size() && l_b < b.size()) {
            if (cmp(a[l_a], b[l_b])) {
                c[i] = a[l_a];
                l_a++;
            } else {
                c[i] = b[l_b];
                l_b++;
            }
        } else if (l_a == a.size()) {
            c[i] = b[l_b];
            l_b++;
        } else {
            c[i] = a[l_a];
            l_a++;
        }
    }
    return c;
}

vector <Person> merge_sort(vector<Person> a, long long l, long long r) {
    if (a.size() <= 1) {
        return a;
    }
    long long m = (l + r) / 2;
    vector <Person> L;
    vector <Person> R;
    for (long long i = l; i < r; ++i) {
        if (i < m) {
            L.push_back(a[i]);
        } else {
            R.push_back(a[i]);
        }
    }
    L = merge_sort(L, l, m);
    R = merge_sort(R, 0, r - m);
    return merge(L, R);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<Person> a(n, {0, 0});
    for (long long i = 0; i < n; ++i) {
        cin >> a[i].id >> a[i].res;
    }
    a = merge_sort(a, 0, n);
    for (Person i : a) {
        cout << i.id << " " << i.res << "\n";
    }
    return 0;
}
