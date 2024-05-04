#include <bits/stdc++.h>
#define double long double
using namespace std;

const double PI = 3.14159265358979323846;
void solve() {
    int n;
    cin >> n;
    vector<pair<double, int>> a;
    for (int i = 0; i < n; i++) {
        double  x, y;
        cin >> x >> y;
        auto ang = atan2(y, x) * 180 / PI;
        a.push_back({ ang + (ang < 0 ? 360 : 0), i + 1 });
    }
    sort(a.begin(), a.end());
    a.push_back({ a[0].first + 360, a[0].second });
    int x, y;
    double delta = 1e5;
    for (int i = 1; i <= n; i++) {
        double d = abs(a[i].first - a[i - 1].first);
        if (d < delta) {
            x = a[i].second;
            y = a[i - 1].second;
            delta = d;
        }
    }
    cout << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}


/*

#include <bits/stdc++.h>
#define double long double
using namespace std;

const double PI = 3.14159265358979323846;
void solve() {
    int n;
    cin >> n;
    vector<pair<double, int>> a;
    for (int i = 0; i < n; i++) {
        cerr << "i  = " << i << endl;
        double  x, y;
        cin >> x >> y;
        auto ang = atan2(y, x) * 180 / PI;
        a.push_back({ ang + (ang < 0 ? 360 : 0), i + 1 });
        cerr << fixed << setprecision(5);
        cerr << "Angle: " << ang << " " << a.back().first << endl;
    }
    sort(a.begin(), a.end());
    a.push_back({ a[0].first + 360, a[0].second });
    int x, y;
    int delta = 1e5;
    for (int i = 1; i <= n; i++) {
        int d = abs(a[i].first - a[i - 1].first);
        cerr << a[i - 1].first << " " << a[i].first << endl;
        if (d < delta) {
            x = a[i].second;
            y = a[i - 1].second;
            delta = d;
        }
    }
    cout << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}*/


// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// template<typename T>
// class Fraction {
// private:
//     T num;
//     T den;

//     T gcd(T a, T b) {
//         while (b != 0) {
//             T temp = b;
//             b = a % b;
//             a = temp;
//         }
//         return a;
//     }

// public:
//     Fraction() :num(0), den(1) {}

//     Fraction(T num, T denom) : num(num), den(denom) {
//         if (den == 0) {
//             std::cerr << "Error: Den cannot be zero." << std::endl;
//             exit(1);
//         }
//         simplify();
//     }

//     void simplify() {
//         T divisor = gcd(num, den);
//         num /= divisor;
//         den /= divisor;
//     }

//     Fraction operator+(const Fraction& other) const {
//         T newNum = num * other.den + other.num * den;
//         T newDen = den * other.den;
//         return Fraction(newNum, newDen);
//     }

//     Fraction operator-(const Fraction& other) const {
//         T newNum = num * other.den - other.num * den;
//         T newDen = den * other.den;
//         return Fraction(newNum, newDen);
//     }

//     Fraction operator*(const Fraction& other) const {
//         T newNum = num * other.num;
//         T newDen = den * other.den;
//         return Fraction(newNum, newDen);
//     }

//     Fraction operator/(const Fraction& other) const {
//         if (other.num == 0) {
//             std::cerr << "Error: Division by zero." << std::endl;
//             exit(1);
//         }
//         T newNum = num * other.den;
//         T newDen = den * other.num;
//         return Fraction(newNum, newDen);
//     }

//     bool operator==(const Fraction& other) const {
//         return num == other.num && (num == 0 || den == other.den);
//     }

//     bool operator!=(const Fraction& other) const {
//         return !(*this == other);
//     }

//     bool operator<(const Fraction& other) const {
//         return num * other.den < other.num * den;
//     }

//     bool operator<=(const Fraction& other) const {
//         return *this < other || *this == other;
//     }

//     bool operator>(const Fraction& other) const {
//         return !(*this <= other);
//     }

//     bool operator>=(const Fraction& other) const {
//         return !(*this < other);
//     }

//     Fraction abs() const {
//         return Fraction(std::abs(num), std::abs(den));
//     }

//     void display() const {
//         cout << num << "/" << den;
//     }
// };Fraction Z(0LL, 1LL);

// struct Point {
//     Fraction<int> x, y;
//     int index;
//     bool operator<(const Point& other) const {
//         return y < other.y;
//     }
// };

// void merge(vector<Point>& a, vector<Point>& b) {
//     a.insert(a.end(), b.begin(), b.end());
// }

// auto dist(Point& a, Point& b) {
//     auto dx = a.x - b.x;
//     auto dy = a.y - b.y;
//     return dx * dx + dy * dy;
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<Point> p(n);
//     for (int i = 0; i < n; i++) {
//         int x, y;
//         cin >> x >> y;
//         p[i] = { Fraction(x, 1LL), Fraction(y, 1LL) , i + 1 };
//     }
//     vector<Point> nw, ne, sw, se;
//     for (auto [x, y, index] : p) {
//         y = x == Z ? Fraction(y < Z ? -1LL : 1LL, 1LL) : y / x.abs();
//         x = x == Z ? x : x / x.abs();
//         if (x >= Z && y >= Z) ne.push_back({ x, y, index });
//         else if (x <= Z && y >= Z) nw.push_back({ x, y, index });
//         else if (x <= Z && y <= Z) sw.push_back({ x, y, index });
//         else se.push_back({ x , y, index });
//     }
//     sort(ne.begin(), ne.end(), [&](const Point& a, const Point& b) {
//         if (a.x == Z) return false;
//         return a.y < b.y;
//         });
//     sort(se.begin(), se.end());
//     sort(nw.begin(), nw.end(), [&](Point& a, Point& b) {
//         return a.y > b.y;
//         });
//     sort(sw.begin(), sw.end(), [&](Point& a, Point& b) {
//         if (a.x == Z) return false;
//         return a.y > b.y;
//         });
//     vector<Point>all;
//     for (auto vec : { ne, nw, sw, se }) merge(all, vec);
//     all.insert(all.end(), all.begin(), all.end());
//     Fraction<int> dis(1e9, 1);
//     Point a, b;
//     for (int i = 1; i < all.size(); i++) {
//         auto d = dist(all[i - 1], all[i]);
//         d = d.abs();
//         if (d < dis) {
//             a = all[i - 1], b = all[i];
//             dis = d;
//         }
//     }
//     cout << a.index << " " << b.index << endl;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
// }





// #include <bits/stdc++.h>
// using namespace std;

// template<typename T>
// class Fraction {
// private:
//     T num;
//     T den;

//     T gcd(T a, T b) {
//         while (b != 0) {
//             T temp = b;
//             b = a % b;
//             a = temp;
//         }
//         return a;
//     }

// public:
//     Fraction() :num(0), den(1) {}

//     Fraction(T num, T denom) : num(num), den(denom) {
//         if (den == 0) {
//             std::cerr << "Error: Den cannot be zero." << std::endl;
//             exit(1);
//         }
//         simplify();
//     }

//     void simplify() {
//         T divisor = gcd(num, den);
//         num /= divisor;
//         den /= divisor;
//     }

//     Fraction operator+(const Fraction& other) const {
//         T newNum = num * other.den + other.num * den;
//         T newDen = den * other.den;
//         return Fraction(newNum, newDen);
//     }

//     Fraction operator-(const Fraction& other) const {
//         T newNum = num * other.den - other.num * den;
//         T newDen = den * other.den;
//         return Fraction(newNum, newDen);
//     }

//     Fraction operator*(const Fraction& other) const {
//         T newNum = num * other.num;
//         T newDen = den * other.den;
//         return Fraction(newNum, newDen);
//     }

//     Fraction operator/(const Fraction& other) const {
//         if (other.num == 0) {
//             std::cerr << "Error: Division by zero." << std::endl;
//             exit(1);
//         }
//         T newNum = num * other.den;
//         T newDen = den * other.num;
//         return Fraction(newNum, newDen);
//     }

//     bool operator==(const Fraction& other) const {
//         return num == other.num && (num == 0 || den == other.den);
//     }

//     bool operator!=(const Fraction& other) const {
//         return !(*this == other);
//     }

//     bool operator<(const Fraction& other) const {
//         return num * other.den < other.num * den;
//     }

//     bool operator<=(const Fraction& other) const {
//         return *this < other || *this == other;
//     }

//     bool operator>(const Fraction& other) const {
//         return !(*this <= other);
//     }

//     bool operator>=(const Fraction& other) const {
//         return !(*this < other);
//     }

//     Fraction abs() const {
//         return Fraction(std::abs(num), std::abs(den));
//     }

//     void display() const {
//         cout << num << "/" << den;
//     }
// };Fraction Z(0, 1);

// struct Point {
//     Fraction<int> x, y;
//     int index;
//     bool operator<(const Point& other) const {
//         return y < other.y;
//     }
// };

// void merge(vector<Point>& a, vector<Point>& b) {
//     a.insert(a.end(), b.begin(), b.end());
// }

// void dbg(vector<Point>& a) {
//     cerr << "starting" << endl;
//     //cerr << fixed << setprecision(10);
//     for (auto& [x, y, _] : a) {
//         x.display();
//         cout << " ";
//         y.display();
//         cerr << endl;
//     }
// }

// auto dist(Point& a, Point& b) {
//     auto dx = a.x - b.x;
//     auto dy = a.y - b.y;
//     return dx * dx + dy * dy;
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<Point> p(n);
//     for (int i = 0; i < n; i++) {
//         int x, y;
//         cin >> x >> y;
//         p[i] = { Fraction(x, 1), Fraction(y, 1) , i + 1 };
//     }
//     vector<Point> nw, ne, sw, se;
//     for (auto [x, y, index] : p) {
//         x.display();
//         cerr << " ";
//         y.display();
//         y = x == Z ? Fraction(y < Z ? -1 : 1, 1) : y / x.abs();
//         cerr << " ";
//         x = x == Z ? x : x / x.abs();
//         x.display();
//         cerr << " ";
//         y.display();
//         cerr << endl;
//         if (x >= Z && y >= Z) ne.push_back({ x, y, index });
//         else if (x <= Z && y >= Z) nw.push_back({ x, y, index });
//         else if (x <= Z && y <= Z) sw.push_back({ x, y, index });
//         else se.push_back({ x , y, index });
//     }
//     sort(ne.begin(), ne.end(), [&](const Point& a, const Point& b) {
//         if (a.x == Z) return false;
//         return a.y < b.y;
//         });
//     sort(se.begin(), se.end());
//     sort(nw.begin(), nw.end(), [&](Point& a, Point& b) {
//         return a.y > b.y;
//         });
//     sort(sw.begin(), sw.end(), [&](Point& a, Point& b) {
//         if (a.x == Z) return false;
//         return a.y > b.y;
//         });
//     dbg(ne); dbg(nw); dbg(sw); dbg(se);

//     vector<Point>all;
//     for (auto vec : { ne, nw, sw, se }) merge(all, vec);
//     all.insert(all.end(), all.begin(), all.end());
//     Fraction<int> dis(1e9, 1);
//     Point a, b;
//     for (int i = 1; i < all.size(); i++) {
//         auto d = dist(all[i - 1], all[i]);
//         d = d.abs();
//         if (d < dis) {
//             a = all[i - 1], b = all[i];
//             dis = d;
//         }
//     }
//     cout << a.index << " " << b.index << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     solve();
// }

/*
#include <bits/stdc++.h>
using namespace std;

const double X = 1e7;
struct Point {
    double x, y;
    int index;
    bool operator<(const Point& other) const {
        return y < other.y;
    }
};

void merge(vector<Point>& a, vector<Point>& b) {
    a.insert(a.end(), b.begin(), b.end());
}

void dbg(vector<Point>& a) {
    cerr << "starting" << endl;
    cerr << fixed << setprecision(10);
    for (auto& [x, y, _] : a) cerr << x << " " << y << endl;
    cerr << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].index = i + 1;
    }
    vector<Point> nw, ne, sw, se;
    for (auto [x, y, index] : p) {
        int m = x < 0 ? -1 : 1;
        x = abs(x);
        Point P = { m * X, y * X / x , index };
        if (P.x >= 0 && P.y >= 0) ne.push_back(P);
        else if (P.x <= 0 && P.y >= 0) nw.push_back(P);
        else if (P.x <= 0 && P.y <= 0) sw.push_back(P);
        else se.push_back(P);
    }
    dbg(ne); dbg(nw); dbg(sw); dbg(se);
    sort(ne.begin(), ne.end());
    sort(se.begin(), se.end());
    sort(nw.begin(), nw.end(), [&](Point& a, Point& b) {
        return a.y > b.y;
        });
    sort(sw.begin(), sw.end(), [&](Point& a, Point& b) {
        return a.y > b.y;
        });
    vector<Point>all;
    for (auto vec : { ne, nw, sw, se }) merge(all, vec);
    all.insert(all.end(), all.begin(), all.end());
    double dis = 1e18;
    Point a, b;
    for (int i = 1; i < all.size(); i++) {
        double d = abs(all[i].y - all[i - 1].y);
        if (d < dis) {
            a = all[i - 1], b = all[i];
            dis = d;
        }
    }
    cout << a.index << " " << b.index << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
*/