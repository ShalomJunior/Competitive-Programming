#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        int g1 = 0, g2 = 0;
        for (int j = 0; j < n; j++) {
            g1 = __gcd(g1, abs(a[j] - a[j % i]));
            g2 = __gcd(g2, abs(a[j] - a[j % (n / i)]));
        }
        if (g1 != 1) ans++;
        if (i == n / i) continue;
        if (g2 != 1) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
