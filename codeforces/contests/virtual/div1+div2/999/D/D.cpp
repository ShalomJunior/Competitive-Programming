#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    multiset<int> ma(a.begin(), a.end());
    multiset<int> mb(b.begin(), b.end());
    while (!ma.empty() && !mb.empty() && ma.size() > mb.size()) {
        int xa = *prev(ma.end());
        int xb = *prev(mb.end());
        mb.erase(prev(mb.end()));
        if (xa > xb) {
            cout << "NO" << endl;
            return;
        }
        else if (xa == xb) {
            ma.erase(prev(ma.end()));
        }
        else {
            mb.insert(xb / 2);
            mb.insert((xb + 1) / 2);
        }
    }
    cout << (ma == mb ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}