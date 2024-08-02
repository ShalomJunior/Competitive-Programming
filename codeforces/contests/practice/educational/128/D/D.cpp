#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    map<int, int> R;
    int ans = 0;
    for (int j = n - 1; j > 0; j--) {
        int tot = 0;
        for (int i = j - 1; i >= 0; i--) {
            if (a[i] == a[j]) ans += tot;
            tot += R[a[i]];
        }
        R[a[j]]++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}