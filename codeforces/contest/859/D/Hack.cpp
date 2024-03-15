#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i) v[i] += v[i - 1];
    }

    for (int i = 0; i < q; i++) {
        ll l, r, k; cin >> l >> r >> k;
        ll temp = (r - l + 1) * k;

        l--, r--;
        if (l > 0) temp += v[l - 1];
        temp += v[n - 1] - v[r];

        cout << ((temp % 2) ? "YES" : "NO") << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}