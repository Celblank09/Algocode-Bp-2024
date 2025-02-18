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

const ld EPS = 1e-8;

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

ld point_point(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld point_segment(Point a, Point b1, Point b2) {
    Point v1 = Point(b1, b2);
    Point v2 = Point(b2, b1);
    Point v1_p = Point(b1, a);
    Point v2_p = Point(b2, a);
    ld res = min(point_point(a, b1), point_point(a, b2));
    if (!lt(v1 % v1_p, 0) && !lt(v2 % v2_p, 0)) {
        ld A, B, C;
        A = v1.y;
        B = -v1.x;
        C = -(A * b1.x + B * b1.y);
        return abs(A * a.x + B * a.y + C) / sqrt(A * A + B * B);
    }
    return res;
}

ld point_ray(Point a, Point b1, Point b2) {
    ld res = point_point(a, b1);
    Point v = Point(b1, b2);
    Point v_p = Point(b1, a);
    ld A, B, C;
    A = v.y;
    B = -v.x;
    C = -(A * b1.x + B * b1.y);
    if (!lt(v % v_p, 0)) {
        res = min(res, abs(A * a.x + B * a.y + C) / sqrt(A * A + B * B));
    }
    return res;
}

ld point_line(Point a, Point b1, Point b2) {
    Point v = Point(b1, b2);
    ld A, B, C;
    A = v.y;
    B = -v.x;
    C = -(A * b1.x + B * b1.y);
    return abs(A * a.x + B * a.y + C) / sqrt(A * A + B * B);
}

ld segment_segment(Point a1, Point a2, Point b1, Point b2) {
    Point v;
    ld A1, B1, C1, A2, B2, C2;
    v = Point(a1, a2);
    A1 = v.y;
    B1 = -v.x;
    C1 = -(A1 * a1.x + B1 * a1.y);
    v = Point(b1, b2);
    A2 = v.y;
    B2 = -v.x;
    C2 = -(A2 * b1.x + B2 * b1.y);
    if (eq(A1 * B2, A2 * B1)) {
        return min(min(point_segment(a1, b1, b2), point_segment(a2, b1, b2)),
                   min(point_segment(b1, a1, a2), point_segment(b2, a1, a2)));
    }
    ld x_int = -(B1 * C2 - B2 * C1) / (B1 * A2 - B2 * A1);
    ld y_int = (A1 * C2 - A2 * C1) / (B1 * A2 - B2 * A1);
    if (eq(point_segment(Point(x_int, y_int), a1, a2), 0) && eq(point_segment(Point(x_int, y_int), b1, b2), 0)) {
        return 0;
    }
    return min(min(point_segment(a1, b1, b2), point_segment(a2, b1, b2)),
               min(point_segment(b1, a1, a2), point_segment(b2, a1, a2)));
}

ld segment_ray(Point a1, Point a2, Point b1, Point b2) {
    Point v;
    ld A1, B1, C1, A2, B2, C2;
    v = Point(a1, a2);
    A1 = v.y;
    B1 = -v.x;
    C1 = -(A1 * a1.x + B1 * a1.y);
    v = Point(b1, b2);
    A2 = v.y;
    B2 = -v.x;
    C2 = -(A2 * b1.x + B2 * b1.y);
    if (eq(A1 * B2, A2 * B1)) {
        return min(min(point_ray(a1, b1, b2), point_ray(a2, b1, b2)), point_segment(b1, a1, a2));
    }
    ld x_int = -(B1 * C2 - B2 * C1) / (B1 * A2 - B2 * A1);
    ld y_int = (A1 * C2 - A2 * C1) / (B1 * A2 - B2 * A1);
    if (eq(point_segment(Point(x_int, y_int), a1, a2), 0) && eq(point_ray(Point(x_int, y_int), b1, b2), 0)) {
        return 0;
    }
    return min(min(point_ray(a1, b1, b2), point_ray(a2, b1, b2)), point_segment(b1, a1, a2));
}

ld segment_line(Point a1, Point a2, Point b1, Point b2) {
    Point v;
    ld A1, B1, C1, A2, B2, C2;
    v = Point(a1, a2);
    A1 = v.y;
    B1 = -v.x;
    C1 = -(A1 * a1.x + B1 * a1.y);
    v = Point(b1, b2);
    A2 = v.y;
    B2 = -v.x;
    C2 = -(A2 * b1.x + B2 * b1.y);
    if (eq(A1 * B2, A2 * B1) && eq(A1 * C2, A2 * C1) && eq(B1 * C2, B2 * B1)) {
        return 0;
    }
    if (eq(A1 * B2, A2 * B1)) {
        return min(point_line(a1, b1, b2), point_line(a2, b1, b2));
    }
    ld x_int = -(B1 * C2 - B2 * C1) / (B1 * A2 - B2 * A1);
    ld y_int = (A1 * C2 - A2 * C1) / (B1 * A2 - B2 * A1);
    if (eq(point_segment(Point(x_int, y_int), a1, a2), 0)) {
        return 0;
    }
    return min(point_line(a1, b1, b2), point_line(a2, b1, b2));
}

ld ray_ray(Point a1, Point a2, Point b1, Point b2) {
    Point v;
    ld A1, B1, C1, A2, B2, C2;
    v = Point(a1, a2);
    A1 = v.y;
    B1 = -v.x;
    C1 = -(A1 * a1.x + B1 * a1.y);
    v = Point(b1, b2);
    A2 = v.y;
    B2 = -v.x;
    C2 = -(A2 * b1.x + B2 * b1.y);
    if (eq(A1 * B2, A2 * B1)) {
        return min(point_ray(a1, b1, b2), point_ray(b1, a1, a2));
    }
    ld x_int = -(B1 * C2 - B2 * C1) / (B1 * A2 - B2 * A1);
    ld y_int = (A1 * C2 - A2 * C1) / (B1 * A2 - B2 * A1);
    if (eq(point_ray(Point(x_int, y_int), a1, a2), 0) && eq(point_ray(Point(x_int, y_int), b1, b2), 0)) {
        return 0;
    }
    return min(point_ray(a1, b1, b2), point_ray(b1, a1, a2));
}

ld ray_line(Point a1, Point a2, Point b1, Point b2) {
    Point v;
    ld A1, B1, C1, A2, B2, C2;
    v = Point(a1, a2);
    A1 = v.y;
    B1 = -v.x;
    C1 = -(A1 * a1.x + B1 * a1.y);
    v = Point(b1, b2);
    A2 = v.y;
    B2 = -v.x;
    C2 = -(A2 * b1.x + B2 * b1.y);
    if (eq(A1 * B2, A2 * B1) && eq(A1 * C2, A2 * C1) && eq(B1 * C2, B2 * B1)) {
        return 0;
    }
    if (eq(A1 * B2, A2 * B1)) {
        return point_line(a1, b1, b2);
    }
    ld x_int = -(B1 * C2 - B2 * C1) / (B1 * A2 - B2 * A1);
    ld y_int = (A1 * C2 - A2 * C1) / (B1 * A2 - B2 * A1);
    if (eq(point_ray(Point(x_int, y_int), a1, a2), 0)) {
        return 0;
    }
    return point_line(a1, b1, b2);
}

ld line_line(Point a1, Point a2, Point b1, Point b2) {
    Point v;
    ld A1, B1, C1, A2, B2, C2;
    v = Point(a1, a2);
    A1 = v.y;
    B1 = -v.x;
    C1 = -(A1 * a1.x + B1 * a1.y);
    v = Point(b1, b2);
    A2 = v.y;
    B2 = -v.x;
    C2 = -(A2 * b1.x + B2 * b1.y);
    if (eq(A1 * B2, A2 * B1) && eq(A1 * C2, A2 * C1) && eq(B1 * C2, B2 * B1)) {
        return 0;
    }
    if (eq(A1 * B2, A2 * B1)) {
        return point_line(a1, b1, b2);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    Point a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << point_point(a, c) << "\n";
    cout << point_segment(a, c, d) << "\n";
    cout << point_ray(a, c, d) << "\n";
    cout << point_line(a, c, d) << "\n";
    cout << point_segment(c, a, b) << "\n";
    cout << segment_segment(a, b, c, d) << "\n";
    cout << segment_ray(a, b, c, d) << "\n";
    cout << segment_line(a, b, c, d) << "\n";
    cout << point_ray(c, a, b) << "\n";
    cout << segment_ray(c, d, a, b) << "\n";
    cout << ray_ray(a, b, c, d) << "\n";
    cout << ray_line(a, b, c, d) << "\n";
    cout << point_line(c, a, b) << "\n";
    cout << segment_line(c, d, a, b) << "\n";
    cout << ray_line(c, d, a, b) << "\n";
    cout << line_line(a, b, c, d) << "\n";
}
