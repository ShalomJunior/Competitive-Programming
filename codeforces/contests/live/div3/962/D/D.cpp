#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 1; i * i * 3 <= n && i * 3 <= x; i++) ans++;
    for (int i = 1; i * i <= n && i + i < x; i++) {
        int f = (n - i * i) / (i + i);
        int s = x - (i + i);
        int mx = min(f, s);
        if (mx >= i) mx--;
        ans += mx * 3;
    }
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b < a; b++) {
            if (a * b > n || a + b >= x) break;
            int f = (n - a * b) / (a + b);
            int s = x - (a + b);
            ans += min({ f, s, a - 1 , b - 1 }) * 6;
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
