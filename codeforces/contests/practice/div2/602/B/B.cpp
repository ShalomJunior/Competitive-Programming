#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const double INF = 1e18;
void solve() {
    int n; cin >> n;
    vector<int> x(n), t(n);
    for (auto& c : x) cin >> c;
    for (auto& c : t) cin >> c;
    auto go = [&](double mid) {
        double l = 0, r = INF;
        for (int i = 0; i < n; i++) {
            l = max(l, x[i] - (mid - t[i]));
            r = min(r, x[i] + (mid - t[i]));
        }
        return make_pair(l, r);
        };
    double L = *max_element(t.begin(), t.end());
    double R = 1e9;
    while (R - L > 1e-7) {
        double mid = (L + R) / 2;
        auto p = go(mid);
        p.F <= p.S ? R = mid : L = mid;
    }
    printf("%f\n", go(L).F);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
