#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n + 1);
    for (auto& c : b) cin >> c;
    int ans = 0;
    bool flag = false;
    int add = INF;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
        if (min(a[i], b[i]) <= b[n] && b[n] <= max(a[i], b[i])) flag = true;
        add = min({ add, abs(a[i] - b[n]), abs(b[i] - b[n]) });
    }
    cout << (ans + 1 + (flag ? 0 : add)) << endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
