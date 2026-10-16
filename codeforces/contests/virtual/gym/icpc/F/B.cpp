#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 8;
const int MOD = 1e9 + 7;

void solve() {
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u][v] = g[v][u] = true;
    }
    auto brute = [&](int l, int r) {
        int z = r - l + 1;
        vector<int> o(z);
        iota(o.begin(), o.end(), l);
        int res = 0;
        do {
            bool f = true;
            for (int i = 0; i < z; i++) {
                if (abs(l + i - o[i]) > e || g[l + i][o[i]]) f = false;
            }
            if (f) res++;
        } while (next_permutation(o.begin(), o.end()));
        return res;
        };
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        if (i <= e + 1) {
            dp[i] = brute(0, i);
        }
        else {
            cout << "i = " << i << " " << brute(i - e, i) << endl;
            dp[i] = dp[i - e - 1] * brute(i - e, i) % MOD;
        }
    }
    for (auto& c : dp) cout << c << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << brute(0, i) << " ";
    cout << endl;

    cout << brute(0, n - 1) << endl;
    cout << dp[n - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}