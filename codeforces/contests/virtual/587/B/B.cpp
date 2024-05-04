#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n; cin >> n;
    vector<Mine> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i + 1;
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i].F * i + 1;
    }
    cout << ans << endl;
    for (auto& c : a) cout << c.S << " ";
    cout << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}