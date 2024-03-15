#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<Mine> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        if (a[i].F % k == 0 && a[i].F) a[i].F = k;
        else a[i].F %= k;
        a[i].S = i + 1;
    }
    sort(a.begin(), a.end(), [&](Mine& a, Mine& b) {
        if (a.F != b.F) return a.F > b.F;
        return a.S < b.S;
        });
    for (int i = 0; i < n; i++) {
        cout << a[i].S << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}