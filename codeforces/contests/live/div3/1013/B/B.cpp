#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.rbegin(), a.rend());
    int ans = 0;
    int i = 0;
    while (i < n) {
        int cnt = 1;
        while (i < n && cnt * a[i] < x) {
            i++;
            cnt++;
        }
        if (i < n) {
            ans++;
            i++;
        }

    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
