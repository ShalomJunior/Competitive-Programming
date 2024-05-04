#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    set<ll> k;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        k.insert(x);
    }

    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        if (a * c <= 0) {
            cout << "NO" << endl;
            continue;
        }
        auto it = k.lower_bound(b);
        ll ans;
        if (it != k.end()) {
            ans = *it;
            if (it != k.begin()) {
                it--;
                if (b - *it < ans - b) ans = *it;
            }
        }
        else { it--; ans = *it; }

        ll t = ans - b;
        if (t * t < 4 * a * c) {
            cout << "YES\n" << ans << endl;
        }
        else { cout << "NO" << endl; }
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}