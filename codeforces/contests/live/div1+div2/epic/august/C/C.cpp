#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

Point projectPointOnLine(const Point& A, const Point& B, const Point& P) {
    double ABx = B.x - A.x;
    double ABy = B.y - A.y;

    double APx = P.x - A.x;
    double APy = P.y - A.y;

    double dotProduct = APx * ABx + APy * ABy;
    double ABLengthSq = ABx * ABx + ABy * ABy;
    double scalar = dotProduct / ABLengthSq;

    Point projection = { A.x + scalar * ABx, A.y + scalar * ABy };
    return projection;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (auto& [x, y] : p) cin >> x >> y;
    Point s, e;
    cin >> s.x >> s.y >> e.x >> e.y;
    bool b = true;
    for (auto& id : p) {
        auto h = projectPointOnLine(s, e, id);
        if (min(s.x, e.x) <= h.x && h.x <= max(s.x, e.x)) {
            b &= distance(s, h) < distance(id, h);
        }
    }
    cout << (b ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
