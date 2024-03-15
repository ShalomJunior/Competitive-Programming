#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r; cin >> l >> r;
    for (int i = l; i <= r; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                int sum = i / j;
                if (sum > 1) {
                    int x = 1, y = sum - 1;
                    cout << x * j << " " << y * j << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
