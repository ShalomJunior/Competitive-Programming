#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mn = *min_element(a.begin(), a.end());
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        int d = a[i] - mn - r;
        if (d > 0) {
            r += d;
        }
        else if (d < 0) {

        }
    }
    cout << l + r + mn << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}