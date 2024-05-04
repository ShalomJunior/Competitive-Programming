#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) b[i] = 2;
        else b[i] = 1;
        sa += a[i]; sb += b[i];
    }
    cout << (sb > sa || n == 1 ? "NO" : "YES") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}