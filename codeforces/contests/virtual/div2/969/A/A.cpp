#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; ) {
        if (i & 1) {
            if (i + 2 <= r) ans++;
            i += 4;
        }
        else {
            i++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}