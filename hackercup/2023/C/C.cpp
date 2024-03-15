#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    map<int, int> pairs;
    for (auto& [k, v] : cnt) {
        pairs[v]++;
    }
    int odds = 0;
    for (auto& [k, v] : pairs) {
        if (v & 1) odds++;
    }
    if (odds > 1)
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}