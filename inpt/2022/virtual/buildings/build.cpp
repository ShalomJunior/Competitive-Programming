#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define mp make_pair

using namespace std;

void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>>v(n);
    multiset<pair<ll, ll>> ms;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        v[i] = mp(a, i);
        ms.insert(mp(i, a));
    }

    sort(v.begin(), v.end());
    vector<ll> ans(n, 1e7);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            ans[v[i].S] = -1;
            break;
        }
        auto mine = mp(v[i].S, v[i].F);
        ms.erase(mine);
        auto it = ms.lower_bound(mine);
        if (it != ms.end()) {
            ans[mine.F] = min(ans[mine.F], abs(mine.F - it->F));
        }
        if (it != ms.begin()) {
            it--;
            ans[mine.F] = min(ans[mine.F], abs(mine.F - it->F));
        }
    }

    for (auto& c : ans)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}