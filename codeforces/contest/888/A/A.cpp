#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, H;
    cin >> n >> m >> k >> H;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        int diff = abs(H - h);
        if (diff && diff % k == 0 && diff / k < m)ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}