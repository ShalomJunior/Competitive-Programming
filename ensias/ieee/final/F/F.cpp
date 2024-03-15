#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll cal(vector<ll> v, ll j) {
    int n = v.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (v[i] - j) * (v[i] - j);
    }
    return ans;
}

int main() {
    ll n; cin >> n;
    vector<ll> v(n);
    for (auto& c : v) cin >> c;

    ll ans = LONG_LONG_MAX;
    for (ll j = -100; j <= 100; j++) {
        ll temp = cal(v, j);
        ans = min(ans, temp);
    }
    cout << ans << endl;
}