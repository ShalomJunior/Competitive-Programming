#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    int diff = y - x, m = 100;
    for (int i = 1; i <= diff; i++) {
        if (diff % i == 0 && (diff / i) + 1 <= n) {
            int cnt = 0;
            for (int j = 0; j < n; j++, cnt++) {
                int v = y - j * i;
                if (v > 0) cout << y - j * i << " ";
                else break;
            }
            for (int j = 1; cnt < n; j++, cnt++) {
                cout << y + j * i << " ";
            }
            cout << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}