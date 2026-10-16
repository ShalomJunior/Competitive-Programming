#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    l--;
    r--;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.begin() + l);
    sort(a.begin() + l, a.begin() + r + 1);
    sort(a.begin() + r + 1, a.end());
    int s = accumulate(a.begin() + l, a.begin() + r + 1, 0LL);
    int d1 = 0;
    for (int i = 0; i < l && r - i >= l && a[i] < a[r - i]; i++)  d1 += a[r - i] - a[i];
    int d2 = 0;
    for (int i = r + 1; i < n && r - (i - (r + 1)) >= l && a[i] < a[r - (i - (r + 1))]; i++) d2 += a[r - (i - (r + 1))] - a[i];
    cout << s - max(d1, d2) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}