#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (auto& c : a) cin >> c;
    sort(a.rbegin(), a.rend());
    double ans = 0;
    double s = 0;
    double p = 1;
    for (auto& c : a) {
        ans = max(ans, c);
        double r = 1. - c;
        if (r > 0) {
            p *= r;
            s += c / r;
            ans = max(ans, p * s);
        }
    }
    cout << setprecision(16) << fixed << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
