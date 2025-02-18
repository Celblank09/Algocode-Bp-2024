#include <bits/stdc++.h>

using namespace std;

using ld = long double;

struct Point {
    ld x, y;
    explicit Point(ld x = 0, ld y = 0) : x(x), y(y) {}
    Point(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    Point operator*(ld k) const {
        return Point(x * k, y * k);
    }
    ld len() const {
        return sqrt(x * x + y * y);
    }
    ld operator%(const Point &p) const { //Скалярное произведение
        return x * p.x + y * p.y;
    }
    ld operator*(const Point &p) const { //Векторное произведение
        return x * p.x - y * p.y;
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

ld angle(Point &a, Point &b) {
    return atan2(a * b, a % b);
}

ld dist(Point &a, Point &b) {
    return Point(a, b).len();
}

const ld EPS = 1e-9;

bool eq(ld x, ld y) {
    return abs(x - y) <= EPS;
}

bool lt(ld x, ld y) {
    return x + EPS < y;
}

bool gt(ld x, ld y) {
    return x - EPS > y;
}

const ld PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(15) << fixed;

    ld a1, b1, c1, a2, b2, c2;
    Point p1_1, p1_2, p2_1, p2_2, v;
    cin >> p1_1 >> p1_2 >> p2_1 >> p2_2;
    v = Point(p1_1, p1_2);
    a1 = v.y;
    b1 = -v.x;
    c1 = -(a1 * p1_1.x + b1 * p1_1.y);

    v = Point(p2_1, p2_2);
    a2 = v.y;
    b2 = -v.x;
    c2 = -(a2 * p2_1.x + b2 * p2_1.y);

    if (eq(a1 * b2, a2 * b1) && eq(a1 * c2, a2 * c1) && eq(c1 * b2, c2 * b1)) {
        cout << "2";
        return 0;
    }
    if (eq(a1 * b2, a2 * b1)) {
        cout << "0";
        return 0;
    }
    cout << "1 " << -(b1 * c2 - b2 * c1) / (b1 * a2 - b2 * a1) << " " << (a1 * c2 - a2 * c1) / (b1 * a2 - b2 * a1);
}
