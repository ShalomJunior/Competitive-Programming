#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int> 
#define F first
#define S second 
using namespace std;

void solve() {
    int n; cin >> n;
    vector<Mine> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a.begin(), a.end());
    vector<int> pre(n), suf(n);
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + i * (a[i].F - a[i - 1].F) + 1;
        suf[n - 1 - i] = suf[n - i] + i * (a[n - i].F - a[n - 1 - i].F) + 1;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[a[i].S] = pre[i] + suf[i] + 1;
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