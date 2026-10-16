#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> g(N + 1);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            int v = i ^ j;
            if (__builtin_popcount(v) == k) g[i].push_back(j);
        }
    }
    int ans = 0;
    vector<int> cnt(N + 1);
    for (int i = 0; i < n; i++) {
        for (auto& c : g[a[i]]) {
            ans += cnt[c];
        }
        cnt[a[i]]++;
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
