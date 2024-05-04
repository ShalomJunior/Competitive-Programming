#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = d / 2;
    while (a + b + c) {
        if (a & 1 && b & 1 && c & 1) ans++;
        if (a % 2 == 0 && b % 2 == 0 && c % 2) ans++;
        int mx = max({ a, b, c });
        if (a == mx) a--;
        else if (b == mx) b--;
        else c--;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}