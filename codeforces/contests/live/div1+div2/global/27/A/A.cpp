#include <bits/stdc++.h> 
#define int long long
using namespace std;

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int k = n - r;
    int ans = m - c + k + (m - 1) * k + (m - 1) * k;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}