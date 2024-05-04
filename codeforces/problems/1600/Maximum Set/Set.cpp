#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 998244353;

int k(int l, int r) {
    int i = 0;
    while ((l << i) <= r)i++;
    return i;
}

void solve() {
    int l, r; cin >> l >> r;

    ll ans = 0;
    int m = k(l, r);
    ans += 1 + (r >> (m - 1)) - l;
    int up = r / (3 * (1 << (m - 2)));
    ll ths = (up < l) ? 0 : up - l + 1;
    ans += ths * (m - 1);
    ans %= MOD;

    cout << m << " " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}