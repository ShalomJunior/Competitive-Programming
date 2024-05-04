#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, n; cin >> a >> b >> n;
    long long ans = b;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        ans += min(a - 1, c);
    }
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}