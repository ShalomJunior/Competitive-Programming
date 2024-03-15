#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    vector<Mine> c(n);
    for (int i = 0; i < n; i++) {
        c[i].F = a[i];
        c[i].S = i;
    }
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    multiset<int> mb(b.begin(), b.end());
    set<Mine> tmp;
    vector<int> ans(n);
    for (int i = n - 1; i >= n - x; i--) {
        auto it = mb.lower_bound(a[i]);
        if (it == mb.begin()) {
            cout << "NO" << endl;
            return;
        }
        --it;
        ans[i] = *it;
        mb.erase(it);
        tmp.insert({ a[i], i });
    }
    for (int i = n - x - 1; i >= 0; i--) {
        auto it = mb.lower_bound(a[i]);
        if (it == mb.end()) {
            if (tmp.empty() || ans[prev(tmp.end())->S] < a[i]) {
                cout << "NO" << endl;
                return;
            }
            int id = prev(tmp.end())->S;
            tmp.erase(prev(tmp.end()));
            ans[i] = ans[id];
            ans[id] = *mb.begin();
            mb.erase(mb.begin());
        }
        else {
            ans[i] = *it;
            mb.erase(it);
        }
    }
    cout << "YES" << endl;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        t[c[i].S] = ans[i];
    }
    for (auto& c : t) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}