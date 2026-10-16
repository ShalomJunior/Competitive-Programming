#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, vector<int>> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int need = a[i] - (n - i + 1);
        if (need >= 0) {
            h[need].push_back(i - 1);
        }
    }
    function<void(int, int, set<int>)> dfs = [&](int r, int s, set<int> d) {
        d.insert(r);
        for (auto& c : h[r]) {
            if (!d.count(r)) {

            }
        }
        };
    for (auto& c : h[0]) {
        dfs(c, );
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
