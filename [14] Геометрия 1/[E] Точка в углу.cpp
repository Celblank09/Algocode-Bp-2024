#include <bits/stdc++.h>

using namespace std;

using ld = long double;

struct Point {
    long long x, y;
    explicit Point(ld x = 0, ld y = 0) : x(x), y(y) {}
    Point(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    long long operator*(const Point &p) const { //Векторное произведение
        return x * p.y - y * p.x;
    }
};

istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

ostream& operator<<(ostream& os, const Point& p) {
    os << p.x << " " << p.y;
    return os;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(15) << fixed;

    Point A, O, B, P, OA, OB, OP;
    cin >> A >> O >> B >> P;
    OA = Point(O, A);
    OB = Point(O, B);
    OP = Point(O, P);
    if (((OA * OP >= 0) == (OA * OB >= 0)) && ((OA * OP >= 0) == (OP * OB >= 0))) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
