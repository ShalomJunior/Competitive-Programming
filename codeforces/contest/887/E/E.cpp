#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    int sum = 0, sq = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
        sq += a * a;
    }
    double a = 4 * n, b = 4 * sum, c = sq - x;
    double delta = b * b - 4 * a * c;
    double x1 = (-b + sqrt(delta)) / (2 * a);
    cout << (long long)x1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}