#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    if (k == 0) {
        cout << 0;
    }
    else {
        k = abs(k);
        if (n * p < k) {
            cout << -1;
        }
        else {
            int ans = k / p;
            if (k % p) ans++;
            cout << ans;
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}