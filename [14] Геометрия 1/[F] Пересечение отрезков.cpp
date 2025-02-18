#include <bits/stdc++.h>

using namespace std;

using ld = long double;

struct Point {
    long long x, y;
    explicit Point(long long x = 0, long long y = 0) : x(x), y(y) {}
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
    Point operator*(long long k) const {
        return Point(x * k, y * k);
    }
    long long len() const {
        return sqrt(x * x + y * y);
    }
    long long operator%(const Point &p) const { //Скалярное произведение
        return x * p.x + y * p.y;
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

    Point a, b, c, d;
    cin >> a >> b >> c >> d;
    Point AB = Point(a, b), AC = Point(a, c), AD = Point(a, d);
    Point CD = Point(c, d), CA = Point(c, a), CB = Point(c, b);
    //cout << (AB * AC) << " " << (AB * AD) << " " << (CD * CA) << " " << (CD * CB) << "\n";
    if ((AB * AC) * (AB * AD) > 0 || (CD * CA) * (CD * CB) > 0) {
        cout << "Empty";
        return 0;
    }
    if (AB * AC != 0 || AB * AD != 0 || CD * CA != 0 || CD * CB != 0) {
        ld a1, b1, c1, a2, b2, c2;
        Point v;
        v = Point(a, b);
        a1 = v.y;
        b1 = -v.x;
        c1 = -(a1 * a.x + b1 * a.y);
        //cout << a1 << " " << b1 << " " << c1 << "\n";

        v = Point(c, d);
        a2 = v.y;
        b2 = -v.x;
        c2 = -(a2 * c.x + b2 * c.y);
        //cout << a2 << " " << b2 << " " << c2 << "\n";
        cout << -(b1 * c2 - b2 * c1) / (b1 * a2 - b2 * a1) << " " << (a1 * c2 - a2 * c1) / (b1 * a2 - b2 * a1);
        return 0;
    }
    ld x1, x2, y1, y2;
    x1 = max(min(a.x, b.x), min(c.x, d.x));
    x2 = min(max(a.x, b.x), max(c.x, d.x));
    y1 = max(min(a.y, b.y), min(c.y, d.y));
    y2 = min(max(a.y, b.y), max(c.y, d.y));
    if (x2 < x1 || y2 < y1) {
        cout << "Empty";
        return 0;
    }
    if (a.x > b.x || (a.x == b.x && a.y > b.y)) {
        swap(a, b);
    }
    if (c.x > d.x || (c.x == d.x && c.y > d.y)) {
        swap(c, d);
    }
    if (a.x > c.x || (a.x == c.x && a.y > c.y)) {
        swap(a, c);
        swap(b, d);
    }
    if (b.x == c.x && b.y == c.y) {
        cout << b;
        return 0;
    }
    if (b.x > d.x || (b.x == d.x && b.y > d.y)) {
        if (c.x == d.x && c.y == d.y) {
            cout << c;
            return 0;
        }
        cout << c << "\n" << d;
        return 0;
    }
    cout << c << "\n" << b;
}
