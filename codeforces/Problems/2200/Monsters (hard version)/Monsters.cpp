#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll need(vector<ll> v) {
    int n = v.size();
    if (n == 1) return v[0] - 1;

    ll ans = v[0] - 1;
    v[0] = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) continue;

        if (v[i] != v[i - 1] + 1) {
            ans += v[i] - v[i - 1] - 1;
            v[i] = v[i - 1] + 1;
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto& c : v)
        cin >> c;

    vector<ll> prefix;
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(prefix.begin(), prefix.end(), v[i]);
        prefix.insert(pos, v[i]);
        cout << need(prefix) << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}