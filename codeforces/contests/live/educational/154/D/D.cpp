#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0, mult = 1;
    for (int i = 1; i < n; i++) {
        a[i] *= mult;
        if (a[i] <= a[i - 1]) {
            int q = a[i - 1] / a[i];
            if (q * a[i] <= a[i - 1]) q++;
            a[i] *= q;
            mult *= q;
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}