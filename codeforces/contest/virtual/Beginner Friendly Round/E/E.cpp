#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 61;
void solve() {
    int a, b; cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int mask = 1LL << i;
        if (~(a & mask) & (b & mask)) {
            cout << -1 << endl;
            return;
        }
        if ((a & mask) ^ (b & mask)) {
            ans |= mask;
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