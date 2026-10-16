#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (auto& c : x) cin >> c;
    sort(x.begin(), x.end());
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (x[i] - x[i - 1] > k) ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}