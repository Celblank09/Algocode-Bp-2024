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

    Point a1, a2, b1, b2, a, b;
    cin >> a1 >> a2 >> b1 >> b2;
    a = Point(a1, a2);
    b = Point(b1, b2);
    cout << a.len() << " " << b.len() << "\n";
    cout << a + b << "\n";
    cout << a % b << " " << a * b << "\n";
    cout << abs(a * b) / 2 << "\n";
    if (atan2(a.y, a.x) < 0) {
        cout << 2 * PI + atan2(a.y, a.x) << " ";
    } else {
        cout << atan2(a.y, a.x) << " ";
    }
    if (atan2(b.y, b.x) < 0) {
        cout << 2 * PI + atan2(b.y, b.x) << "\n";
    } else {
        cout << atan2(b.y, b.x) << "\n";
    }
    if (angle(a, b) < 0) {
        cout << 2 * PI + angle(a, b) << "\n";
        cout << (2 * PI + angle(a, b)) / (2 * PI);
    } else {
        cout << angle(a, b) << "\n";
        cout << angle(a, b) / (2 * PI);
    }
}
