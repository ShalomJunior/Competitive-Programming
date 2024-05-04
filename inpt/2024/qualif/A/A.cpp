#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    complex d = (1, 2);
    vector<double> x, y;
    for (int i = 0; i < n; i++) {
        double x, y, w, h, angle;
        cin >> x >> y >> w >> h >> angle;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    double x1 = x[0], y1 = y[0];
    double x2 = x.back(), y2 = y.back();
    cout << (x1 + x2) / 2 << " " << (y1 + y2) / 2 << " ";
    cout << x2 - x1 << " " << y2 - y1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << cos(45) << endl;
    solve();
}