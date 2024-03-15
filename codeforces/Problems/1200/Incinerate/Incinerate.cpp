#include <bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
#define mp make_pair
using namespace std;

void solve() {
    ll n, k; cin >> n >> k;

    vector<ll> h(n), p(n);
    for (auto& c : h)cin >> c;
    for (auto& c : p)cin >> c;

    priority_queue<pr>pq;
    multiset<pr> ms;
    for (int i = 0; i < n; i++) {
        pq.push(mp(-h[i], p[i]));
        ms.insert(mp(p[i], h[i]));
    }

    ll delta = 0;
    while (k > 0) {
        delta -= k;
        while (!pq.empty() && pq.top().first >= delta) {
            auto tp = pq.top();
            ms.erase(mp(tp.second, -tp.first));
            pq.pop();
        }
        if (pq.empty()) {
            cout << "YES" << endl;
            return;
        }
        k -= ms.begin()->first;
    }
    cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}