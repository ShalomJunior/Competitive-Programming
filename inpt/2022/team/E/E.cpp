#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    set<pair<int, int>> b;
    set<pair<int, int>> r;
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        b.insert({ h, i });
        r.insert({ i, h });
    }
    vector<int> ans(n, INF);
    set<pair<int, int>> to_del;
    for (auto it = b.begin(); it != b.end();it++) {
        pair<int, int> p = { it->S,it->F };
        r.erase(p);
        auto t = r.lower_bound({ it->S, 0 });
        if (t != r.end()) {
            ans[it->S] = min(ans[it->S], abs(it->S - t->F));
        }

        if (t != r.begin()) {
            t--;
            ans[it->S] = min(ans[it->S], abs(t->F - it->S));
        }
        auto f = next(it);
        if (f != r.end() && f->F == it->F) {
            r.insert(p);
            to_del.insert(p);
        }
        else {
            while (!to_del.empty()) {
                r.erase(*to_del.begin());
                to_del.erase(to_del.begin());
            }
        }
    }
    for (auto& c : ans) {
        cout << ((c == INF) ? -1 : c) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}