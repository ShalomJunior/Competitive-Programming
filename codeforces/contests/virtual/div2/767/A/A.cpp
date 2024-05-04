#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first;
    for (int i = 0; i < n; i++) cin >> p[i].second;
    sort(p.begin(), p.end());
    int ans = k;
    for (int i = 0; i < n; i++) {
        if (ans < p[i].first) break;
        ans += p[i].second;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}