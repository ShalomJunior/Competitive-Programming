#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> p(2 * n);
    for (auto& c : p) {
        cin >> c;
        ans += abs(c);
    }
    sort(p.begin(), p.end());
    if (n == 1) {
        ans = min(ans, abs(p[0] - p[1]));
    }
    else if (n == 2) {
        int curr = 0;
        for (auto& c : p) curr += abs(c - 2);
        ans = min(ans, curr);
    }
    if (n % 2 == 0) {
        int curr = abs(p.back() - n);
        for (int i = 0; i + 1 < 2 * n; i++) curr += abs(p[i] + 1);
        ans = min(ans, curr);
    }
    else {}
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
