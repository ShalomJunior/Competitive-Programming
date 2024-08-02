#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 100;
    for (int x = 1; x <= 10; x++) {
        int f = abs(x - a) + abs(x - b) + abs(x - c);
        ans = min(ans, f);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
