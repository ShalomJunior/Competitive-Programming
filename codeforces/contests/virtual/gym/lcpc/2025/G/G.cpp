#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 2) {
        cout << 0 << endl;
    }
    else {
        cout << n - 1 << endl;
        for (int i = 2; i <= n; i++) {
            cout << (i & 1 ? 'B' : 'F');
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}