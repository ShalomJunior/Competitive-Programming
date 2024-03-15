#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, d; cin >> n >> d;
    vector<ll> v(n);
    for (auto& c : v) cin >> c;

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) {
            ll diff = v[i - 1] - v[i];
            ll plus = diff / d + 1;
            v[i] += plus * d;
            ans += plus;
        }
    }

    cout << ans << endl;
}