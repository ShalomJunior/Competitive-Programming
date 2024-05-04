#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> d(n);
    for (auto& c : d) cin >> c;
    map<int, int> h;
    for (auto& c : d) h[c]++;
    vector<int> p;
    for (auto& [k, v] : h) p.push_back(k);
    reverse(p.begin(), p.end());
    int m = p.size();
    int tot = 0;
    for (int i = 0; i < m; i++) {
        tot += (p[0] - p[i]) * h[p[i]];
    }
    int x = 0, y = 0, s = n;
    for (int i = 0; i < m; i++) {
        y += tot * h[p[i]];
        s -= h[p[i]];
        if (i < m - 1) {
            tot -= s * (p[i] - p[i + 1]);
            x += (p[i] - p[i + 1]);
        }
    }
    cout << x - y << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}