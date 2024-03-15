#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

const ll INF = 1e15;

void solve() {
    int n; cin >> n;
    vector<pair<ll, ll>> v(n);
    set<pair<ll, ll>> s;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        s.insert(make_pair(i, a));
        v[i] = make_pair(a, i);
    }

    sort(v.begin(), v.end());
    vector<ll> ans(n, INF);
    for (int i = 0; i < n - 1; i++) {
        ll a = v[i].F, j = v[i].S;
        auto mine = make_pair(j, a);
        s.erase(mine);
        auto it = s.lower_bound(mine);
        if (it != s.end()) {
            ans[j] = min(ans[j], abs(it->F - j));
        }
        if (it != s.begin()) {
            it--;
            ans[j] = min(ans[j], abs(it->F - j));
        }
    }
    ans[v.back().S] = -1;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--)solve();
}