#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (x < y) swap(x, y);
    if (x == 0 || y != 0 || (n - 1) % x) {
        cout << -1 << endl;
        return;
    }
    int winner = 1;
    for (int i = 2, s = 0; i <= n; i++, s++) {
        if (s == x) {
            winner = i;
            s = 0;
        }
        cout << winner << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}