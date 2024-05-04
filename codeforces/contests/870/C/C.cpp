#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    if (n <= m) { cout << ((n == 1) ? "YES" : "NO") << endl; return; }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0 && (n / i <= m || i <= m)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
