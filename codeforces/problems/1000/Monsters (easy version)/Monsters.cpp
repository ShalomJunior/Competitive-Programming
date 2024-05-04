#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto& c : v)
        cin >> c;

    sort(v.begin(), v.end());
    ll ans = v[0] - 1;
    v[0] = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) continue;

        if (v[i] != v[i - 1] + 1) {
            ans += v[i] - v[i - 1] - 1;
            v[i] = v[i - 1] + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}