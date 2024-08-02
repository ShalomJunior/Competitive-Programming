#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int x = 0; x * 3 <= n; x++) {
        int r = n - x * 3;
        for (int y = 0; y * 5 <= r; y++) {
            int q = r - y * 5;
            if (q % 7 == 0) {
                cout << x << " " << y << " " << q / 7 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
