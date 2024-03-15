#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int s = 0, i = 0; i < n; i++) {
        b[i] = s >= a[i].F;
        s += a[i].F;
    }
    vector<int> c(n);
    for (int l = n, i = n - 1; i >= 0; i--) {
        c[i] = l;
        if (!b[i]) l = i;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[a[i].S] = i + c[i] - (i + 1);
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
