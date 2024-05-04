#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;

void out(vector<ll>& v) {
    cout << v.size() << " ";
    for (auto& c : v)
        cout << c << " ";
    cout << endl;
}

void solve() {
    ll n, s1, s2; cin >> n >> s1 >> s2;

    priority_queue<pair<ll, ll>>pq;
    for (int i = 1; i <= n; i++) {
        int r; cin >> r;
        pq.push(mp(r, i));
    }

    ll mn = min(s1, s2), mx = max(s1, s2);
    vector<ll> a, b;
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();

        ll la = (ll)(a.size() + 1);
        ll lb = (ll)(b.size() + 1);

        if (la * mn < lb * mx) a.push_back(p.second);
        else b.push_back(p.second);
    }

    if (s1 < s2) {
        out(a);out(b);
    }
    else {
        out(b); out(a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}