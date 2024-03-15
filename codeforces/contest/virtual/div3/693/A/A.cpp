#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, h, n; cin >> w >> h >> n;
    int ans = 1;
    while (w % 2 == 0) ans *= 2, w /= 2;
    while (h % 2 == 0) ans *= 2, h /= 2;
    cout << (ans >= n ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}