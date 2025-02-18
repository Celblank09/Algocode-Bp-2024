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

    ld a, b, c;
    Point p;
    cin >> p >> a >> b >> c;
    cout << abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
}
