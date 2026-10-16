#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int o = (n * m) / k;
    vector<int> cnt(k + 1, o);
    set<int> in;
    for (int i = 1; i <= k; i++) in.insert(i);
    int val = 1;
    auto nxt = [&]() {
        auto it = in.upper_bound(val);
        if (it == in.end()) {
            assert(*in.begin() != val);
            val = *in.begin();
        }
        else {
            val = *it;
        }
        };
    vector<vector<int>> ans(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
        int ni = 0;
        int nj = j;
        while (nj >= 0 && ni < n) {
            while (ni > 0 && ans[ni - 1][nj] == val) nxt();
            while (nj > 0 && ans[ni][nj - 1] == val) nxt();
            ans[ni][nj] = val;
            if (--cnt[val] == 0) {
                in.erase(val);
                nxt();
            }
            nj--;
            ni++;
        }
    }
    for (int i = 1; i < n; i++) {
        int ni = i;
        int nj = m - 1;
        while (nj >= 0 && ni < n) {
            while (ni > 0 && ans[ni - 1][nj] == val) nxt();
            while (nj > 0 && ans[ni][nj - 1] == val) nxt();
            ans[ni][nj] = val;
            if (--cnt[val] == 0) {
                in.erase(val);
                nxt();
            }
            nj--;
            ni++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
