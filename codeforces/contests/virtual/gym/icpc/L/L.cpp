#include <bits/stdc++.h>
#define double long double
using namespace std;

double pw(double x) { return x * x; }
double dis(double x, double y) { return sqrt(pw(x) + pw(y)); }
void solve() {
    double x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    double x2, y2, r2;;
    cin >> x2 >> y2 >> r2;
    double len = dis(x2 - x1, y2 - y1);
    double d = r1 + r2 - len;
    double dx = abs(x2 - x1) * (r1 - d / 2) / len;
    double X = x1 < x2 ? x1 + dx : x1 - dx;
    double h = sqrt(pw(r1 - d / 2) - pw(dx));
    double Y = y1 < y2 ? y1 + h : y1 - h;
    cout << fixed << setprecision(15);
    cout << X << " " << Y << " " << d / 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}