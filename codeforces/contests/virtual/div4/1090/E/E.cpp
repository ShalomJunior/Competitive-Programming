#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) cin >> a[i];
    sort(a.rbegin() + 1, a.rend());
    int k = 0;
    for (int j = 1; j < n; j++) {
        int v = j * (j - 1) / 2;
        k += v % 2;
    }
    int ans = 0;
    vector<int> dp(k + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {

        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}