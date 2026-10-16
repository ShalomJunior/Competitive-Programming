#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto& c : x) cin >> c;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    int L = 0, R = x[1] - x[0];
    for (int i = 1; i < n; i++) {
        int d = x[i] - x[i - 1];
        swap(L, R);
        L = max(d - L, 0LL);
        R = d - R;
        if (i < n - 1) {
            R = min(R, x[i + 1] - x[i]);
        }
        if (L >= R) {
            L = 0;
            R = (i < n - 1) ? x[i + 1] - x[i] : INF;
        }
        else {
            L = max(L, 0LL);
            ans++;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
