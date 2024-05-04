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
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        pre[i] = a[i].F + (i ? pre[i - 1] : 0);
    }
    vector<int> ans;
    ans.push_back(a[n - 1].S);
    for (int i = n - 2; i >= 0; i--) {
        if (pre[i] >= a[i + 1].F) ans.push_back(a[i].S);
        else break;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c + 1 << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}