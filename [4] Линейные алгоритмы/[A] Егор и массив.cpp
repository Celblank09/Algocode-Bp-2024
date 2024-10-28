#include <bits/stdc++.h>

using namespace std;

struct operation {
    long long l;
    long long r;
    long long d;
};

int main() {
    long long n, m, k, l, r, c_operations_zero = 0, a_zero = 0;
    cin >> n >> m >> k;
    vector <long long> a(n, 0);
    vector <operation> operations(m, {0, 0, 0});
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (long long i = 0; i < m; ++i) {
        cin >> operations[i].l >> operations[i].r >> operations[i].d;
    }
    vector <long long> razn(m + 1, 0);
    vector <long long> razn_a(n + 1, 0);
    vector <long long> itog_a(n + 1, 0);
    for (long long i = 0; i < k; ++i) {
        cin >> l >> r;
        razn[l - 1]++;
        razn[r]--;
        c_operations_zero += (l == 1);
    }

    vector <long long> c_operations(m, 0);
    c_operations[0] = c_operations_zero;
    for (long long i = 1; i < m; ++i) {
        c_operations[i] = c_operations[i - 1] + razn[i];
    }
    for (long long i = 0; i < m; ++i) {
        razn_a[operations[i].l - 1] += operations[i].d * c_operations[i];
        razn_a[operations[i].r] -= operations[i].d * c_operations[i];
        a_zero += (operations[i].l == 1) * (operations[i].d * c_operations[i]);
    }
    itog_a[0] = a_zero;
    for (long long i = 1; i < n; ++i) {
        itog_a[i] = itog_a[i - 1] + razn_a[i];
    }
    for (long long i = 0; i < n; ++i) {
        cout << a[i] + itog_a[i] << " ";
    }
}
