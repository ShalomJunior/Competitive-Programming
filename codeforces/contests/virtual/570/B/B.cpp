#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int INF = 1e9;
void solve() {
    int n, k; cin >> n >> k;
    vector<Mine> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i].F = max(0, x - k);
        a[i].S = x + k;
    }
    sort(a.begin(), a.end());
    int L = 0, R = INF;
    for (auto& [l, r] : a) {
        L = max(L, l);
        R = min(R, r);
    }
    cout << (L > R ? -1 : R) << endl;
}

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}