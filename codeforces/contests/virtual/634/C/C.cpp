#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x]++;
    }
    int ans = 0;
    for (auto& [k, cnt] : h) {
        int m = h.size();
        ans = max(ans, min(cnt, m - 1));
        ans = max(ans, min(cnt - 1, m));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}