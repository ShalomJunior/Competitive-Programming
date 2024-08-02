#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int mn = y / 2;
    int r = mn * 7;
    if (y % 2) {
        mn++;
        r += 11;
    }
    int ans = mn;
    if (x > r) {
        x -= r;
        ans += (x + 14) / 15;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
