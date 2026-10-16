#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

int mult(int a, int b) {
    return (a % MOD) * (b % MOD) % MOD;
}

void solve() {
    int m, q;
    cin >> m >> q;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        a[i] = s.length();
    }
    while (q--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (a[i] <= n) {
                ans += mult(n - a[i] + 1, power(26, n - a[i]));
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}