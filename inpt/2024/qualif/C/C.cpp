#include <bits/stdc++.h>
#define double long double
using namespace std;

constexpr double PI = 3.14159265358979323846;
void solve() {
    int n;
    cin >> n;
    vector<double> X, Y;
    for (int i = 0; i < n; i++) {
        double x, y, w, h, ang;
        cin >> x >> y >> w >> h >> ang;
        ang = ang * PI / 180.0;
        complex C(cos(ang), sin(ang));
        for (double dx : {x - w / 2, x + w / 2}) {
            for (double dy : {y - h / 2., y + h / 2}) {
                auto Z = C * (complex(dx, dy) - complex(x, y)) + complex(x, y);
                X.push_back(Z.real());
                Y.push_back(Z.imag());
            }
        }
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    double x1 = X[0], y1 = Y[0];
    double x2 = X.back(), y2 = Y.back();
    cout << (x1 + x2) / 2 << " " << (y1 + y2) / 2 << " ";
    cout << x2 - x1 << " " << y2 - y1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}