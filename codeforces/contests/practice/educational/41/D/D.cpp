#include <bits/stdc++.h>
#define int long long
using namespace std;

template<class T>
struct Point {
    T x;
    T y;
    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}

    Point& operator+=(Point p)& {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point& operator-=(Point p)& {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point& operator*=(T v)& {
        x *= v;
        y *= v;
        return *this;
    }
    Point operator-() const {
        return Point(-x, -y);
    }
    friend Point operator+(Point a, Point b) {
        return a += b;
    }
    friend Point operator-(Point a, Point b) {
        return a -= b;
    }
    friend Point operator*(Point a, T b) {
        return a *= b;
    }
    friend Point operator*(T a, Point b) {
        return b *= a;
    }
    friend bool operator==(Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }
    friend std::istream& operator>>(std::istream& is, Point& p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream& operator<<(std::ostream& os, Point p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

template<class T>
T dot(Point<T> a, Point<T> b) {
    return a.x * b.x + a.y * b.y;
}

template<class T>
T cross(Point<T> a, Point<T> b) {
    return a.x * b.y - a.y * b.x;
}

template<class T>
T square(Point<T> p) {
    return dot(p, p);
}

template<class T>
double length(Point<T> p) {
    return std::sqrt(double(square(p)));
}

long double length(Point<long double> p) {
    return std::sqrt(square(p));
}

template<class T>
struct Line {
    Point<T> a;
    Point<T> b;
    Line(Point<T> a_ = Point<T>(), Point<T> b_ = Point<T>()) : a(a_), b(b_) {}
};

template<class T>
bool pointOnLine(Point<T> p, Line<T> l) {
    return cross(p - l.a, l.b - l.a) == 0;
}

void solve() {
    int n;
    cin >> n;
    vector<Point<int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    if (n < 3) {
        cout << "YES" << endl;
        return;
    }
    int j = 0;
    while (pointOnLine(p[j], Line(p[0], p[1]))) j++;
    if (j == n) {
        cout << "YES" << endl;
        return;
    }
    auto check = [&](Line<int> L) {
        vector<Point<int>> out;
        for (auto& c : p) {
            if (!pointOnLine(c, L)) out.push_back(c);
        }
        int m = out.size();
        if (m < 3) return true;
        for (int i = 0; i < m; i++) {
            if (!pointOnLine(out[i], Line(out[0], out[1]))) {
                return false;
            }
        }
        return true;
        };
    cerr << "j = " << j << endl;
    cout << (check(Line(p[0], p[1])) || check(Line(p[0], p[j])) || check(Line(p[1], p[j])) ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
