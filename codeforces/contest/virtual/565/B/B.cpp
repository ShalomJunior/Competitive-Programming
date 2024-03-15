#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a = 0, b = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 3 == 0) ans++;
        else if (x % 3 == 1) a++;
        else b++;
    }
    int m = min(a, b);
    ans += m; a -= m; b -= m;
    ans += max(a, b) / 3;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}