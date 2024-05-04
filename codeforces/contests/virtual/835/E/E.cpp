#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll inv(vector<int>& v) {
    ll n = v.size();
    vector<ll> dp(n);
    dp[n - 1] = 0;
    for (ll i = n - 2; i >= 0; i--) {
        dp[i] = dp[i + 1] + (ll)v[i + 1];
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (v[i] == 1)
            ans += (ll)(n - 1 - i) - dp[i];
    }

    return ans;
}

ll frzero(vector<int>v) {
    ll n = v.size();
    bool done = false;
    for (auto& c : v) {
        if (c == 0) {
            c = 1;
            done = true;
            break;
        }
    }

    return (done) ? inv(v) : n - 1;
}

ll lone(vector<int> v) {
    ll n = v.size();
    bool done = false;
    for (ll i = n - 1; i >= 0; i--) {
        if (v[i] == 1) {
            v[i] = 0;
            done = true;
            break;
        }
    }

    return (done) ? inv(v) : n - 1;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);

    for (auto& c : v)
        cin >> c;

    ll actual = inv(v);
    ll f = frzero(v);
    ll l = lone(v);

    ll mx = max(actual, f);
    mx = max(mx, l);
    cout << mx << endl;

}


int main() {
    int t; cin >> t;
    while (t--) solve();
}