#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> divs(N);
    int mx = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
            mx = max(mx, (int)divs[j].size());
        }
    }
    cout << "mx = " << mx << endl;
    vector<int> ans(N);
    ans[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> p;
        for (auto& c : divs[a[i]]) p.push_back({ c, ans[c - 1] });
        for (auto [c, v] : p) {
            ans[c] += v;
            ans[c] %= MOD;
        }
    }
    int s = accumulate(ans.begin(), ans.end(), 0LL) - 1;
    cout << s % MOD << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
