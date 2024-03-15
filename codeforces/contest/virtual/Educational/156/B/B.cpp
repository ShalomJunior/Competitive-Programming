#include <bits/stdc++.h>
using namespace std;

void solve() {
    long double xh, yh, xa, ya, xb, yb;
    cin >> xh >> yh >> xa >> ya >> xb >> yb;
    vector<long double> ans;
    long double oa = hypot(xa, ya);
    long double ob = hypot(xb, yb);
    long double ha = hypot(xh - xa, yh - ya);
    long double hb = hypot(xh - xb, yh - yb);
    long double ab = hypot(xa - xb, ya - yb);
    ans.push_back(max(oa, ha));
    ans.push_back(max(ob, hb));
    ans.push_back(max(max(oa, ab / 2.), hb));
    ans.push_back(max(max(ob, ab / 2.), ha));
    sort(ans.begin(), ans.end());
    printf("%.10Lf\n", ans[0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
