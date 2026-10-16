#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = INF;
    int l = 0;
    int r = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < n; i++) {
        int k = n - i;
        ans = min(ans, i * a[i] - l + r - k * a[i]);
        l += a[i];
        r -= a[i];
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}