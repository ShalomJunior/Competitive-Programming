#include <bits/stdc++.h>
#define double long double
#define F first
#define S second
using namespace std;

struct Point {
    int id;
    double x, y;
};

bool comp_x(const Point& A, const Point& B) {
    return (A.x < B.x || (A.x == B.x && A.y < B.y));
}

bool comp_y(const Point& A, const Point& B) {
    return (A.y < B.y);
}

double min_dist = 1e20;
pair<int, int> best;
vector<Point> p, t;

double dist(const Point& A, const Point& B) {
    return hypot(A.x - B.x, A.y - B.y);
}

void update(const Point& A, const Point& B) {
    double d = dist(A, B);
    if (d < min_dist) {
        min_dist = d;
        best = { min(A.id, B.id), max(A.id, B.id) };
    }
}

void brute(int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = i + 1; j < r; j++) {
            update(p[i], p[j]);
        }
    }
}

void rec(int l, int r) {
    if (r - l <= 3) {
        brute(l, r);
        sort(p.begin() + l, p.begin() + r, comp_y);
        return;
    }

    int mid = (l + r) / 2;
    auto mid_p = p[mid];

    rec(l, mid);
    rec(mid, r);

    merge(p.begin() + l, p.begin() + mid, p.begin() + mid, p.begin() + r, t.begin(), comp_y);
    copy(t.begin(), t.begin() + r - l, p.begin() + l);

    int under = 0;

    for (int i = r - 1; i >= l; i--) {
        if (abs(p[i].x - mid_p.x) < min_dist) {
            for (int j = i - 1; j >= r && p[i].y - p[j].y < min_dist; j--) {
                update(p[i], p[j]);
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    p.resize(n);
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }

    sort(p.begin(), p.end(), comp_x);
    rec(0, n);
    cout << best.F << " " << best.S << " ";
    cout << fixed << setprecision(6) << min_dist << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}