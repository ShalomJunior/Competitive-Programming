#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = n - 1; i >= 0;) {
        int cnt = 0;
        int j = i;
        for (; j >= 0; j--) {
            cnt++;
            if (cnt * a[j] >= x) {
                ans++;
                i = j - 1;
                break;
            }
        }
        i = j - 1;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
