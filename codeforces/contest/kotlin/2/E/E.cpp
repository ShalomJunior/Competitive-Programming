#include <bits/stdc++.h>
using namespace std;


int dig(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    long long ans = 1;
    while (n) {
        int x = n % 10;
        ans *= (x + 1) * (x + 2) / 2;
        n /= 10;
    }
    cout << ans << endl;
}

int main() {
    int n = 38;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; i + j <= n; j++) {
            if (dig(i) + dig(j) + dig(n - i - j) == dig(n)) {
                cout << i << " " << j << " " << n - i - j << endl;
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
