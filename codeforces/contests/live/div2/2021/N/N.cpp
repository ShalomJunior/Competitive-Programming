#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        for (auto& [k, v] : cnt) v++;
        cnt[id] = 0;
        int r = n - cnt.size();
        int res = r * (i + 1);
        for (auto& [k, v] : cnt) res += v;
        cout << res << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
