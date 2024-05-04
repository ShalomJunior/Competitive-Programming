#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    int pre = 0;
    long long ans = 0;
    for (auto& [k, v] : cnt) {
        if (v < 2) {
            pre += v;
            continue;
        }
        ans += (1LL * v * (v - 1) / 2) * pre;
        if (v >= 3) ans += 1LL * v * (v - 1) * (v - 2) / 6;
        pre += v;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
