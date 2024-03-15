#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 32;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int j = 0; j <= N; j++) {
        int mask = 1LL << j;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] & mask)y++;
            else x++;
        }
        if (y >= x)ans |= mask;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}