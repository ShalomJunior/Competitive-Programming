#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point {
    int x, y, id;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int crossProduct(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point> points) {
    int n = points.size();
    if (n < 3) return {};

    sort(points.begin(), points.end());

    vector<Point> lower;
    for (const Point& p : points) {
        while (lower.size() >= 2 && crossProduct(lower[lower.size() - 2], lower[lower.size() - 1], p) <= 0)
            lower.pop_back();
        lower.push_back(p);
    }

    vector<Point> upper;
    for (int i = n - 1; i >= 0; --i) {
        while (upper.size() >= 2 && crossProduct(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) <= 0)
            upper.pop_back();
        upper.push_back(points[i]);
    }

    lower.pop_back();
    upper.pop_back();

    lower.insert(lower.end(), upper.begin(), upper.end());

    return lower;
}

void printConvexHull(const vector<Point>& hull) {
    for (const Point& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

void solve() {
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i + 1;
    }
    auto o = convexHull(a);
    if (o.empty()) o = a;
    o.push_back(o[0]);
    int ans = 0;
    for (int j = 0; j + 1 < o.size(); j++) {
        ans += abs(o[j].x - o[j + 1].x + o[j].y - o[j + 1].y);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
