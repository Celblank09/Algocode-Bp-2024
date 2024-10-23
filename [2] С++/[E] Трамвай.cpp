#include <bits/stdc++.h>

using namespace std;

struct People {
    long long start;
    long long end;
    long long a;
    long long b;
};

int main() {
    long long n, m, p;
    cin >> n >> m >> p;
    vector<People> peoples(n, {0, 0, 0, 0});
    set<long long> stops;
    set<long long> sitting_peoples;
    set<long long> standing_peoples;
    map<long long, vector<long long>> in_stops;
    map<long long, vector<long long>> out_stops;
    long long res = 0, cur = 0;
    for (long long i = 0; i < n; ++i) {
        cin >> peoples[i].a >> peoples[i].b >> peoples[i].start >> peoples[i].end;
        stops.insert(peoples[i].start);
        stops.insert(peoples[i].end);
        in_stops[peoples[i].start].push_back(i);
        out_stops[peoples[i].end].push_back(i);
    }
    for (long long i : stops) {
        res += cur;
        for (long long j : out_stops[i]) {
            if (sitting_peoples.count(peoples[j].a - peoples[j].b)) {
                cur -= peoples[j].a;
                sitting_peoples.erase(peoples[j].a - peoples[j].b);
            } else {
                cur -= peoples[j].b;
                standing_peoples.erase(peoples[j].a - peoples[j].b);
            }
        }
        for (long long j : in_stops[i]) {
            cur += peoples[j].b;
            standing_peoples.insert(peoples[j].a - peoples[j].b);
        }
        while (sitting_peoples.size() < m && !standing_peoples.empty() && *standing_peoples.rbegin() > 0) {
            auto stand = standing_peoples.rbegin();
            sitting_peoples.insert(*stand);
            cur += *stand;
            standing_peoples.erase(*stand);
        }
        while (!standing_peoples.empty() && !standing_peoples.empty() &&
               *standing_peoples.rbegin() > 0 &&
               *standing_peoples.rbegin() > *sitting_peoples.begin()) {
            auto stand = standing_peoples.rbegin();
            auto sit = sitting_peoples.begin();
            cur += *stand;
            cur -= *sit;
            standing_peoples.insert(*sit);
            sitting_peoples.insert(*stand);
            standing_peoples.erase(*stand);
            sitting_peoples.erase(*sit);
        }
    }
    cout << res + cur;
}
