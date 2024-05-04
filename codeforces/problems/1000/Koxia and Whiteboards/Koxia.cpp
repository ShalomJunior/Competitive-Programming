#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    ll v;
    multiset<ll> s;
    for (int i = 0; i < n; i++) {
        cin >> v;
        s.insert(v);
    }

    for (int i = 0; i < m; i++) {
        cin >> v;
        s.erase(s.begin());
        s.insert(v);
    }

    ll mx = accumulate(s.begin(), s.end(), 0LL);
    cout << mx << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}