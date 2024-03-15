#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x]++;
    }
    int M = 0;
    map<int, int> cnt;
    for (auto& [k, v] : h) {
        cnt[v]++;
        M = max(M, v);
    }
    int ans = 1e9, pass = 0;
    for (int i = M; i > 0; i--) {
        pass += cnt[i];
        ans = min(ans, n - pass * i);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}