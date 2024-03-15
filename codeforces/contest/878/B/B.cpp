#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (k < 50 && 1LL << k <= n + 1) {
        cout << (1LL << k) << endl;
        return;
    }
    long long ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (n & (1 << i) && i <= k) {
            ans += 1LL << i;
        }
    }
    cout << ans + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}