#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b;
    for (int i = 0; i + 1 < n; i++) b.push_back(a[i] - a[i + 1]);
    sort(b.begin(), b.end());
    int ans = a[n - 1] - a[0];
    for (int i = 0; i < k - 1; i++) ans += b[i];
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
