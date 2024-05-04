#include <bits/stdc++.h>
#define double long double
using namespace std;

void solve() {
    int n; double d, h;
    cin >> n >> d >> h;
    vector<int> y(n);
    for (auto& c : y)cin >> c;
    double alpha = d / 2 * h, ans = 0;
    for (int i = 0; i < n; i++) {
        ans += d * h / 2;
        if (!i || y[i - 1] + h <= y[i])continue;
        double hx = y[i - 1] + h - y[i];
        double dx = 2 * alpha * hx;
        ans -= hx * dx / 2;
    }
    printf("%.8Lf\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}