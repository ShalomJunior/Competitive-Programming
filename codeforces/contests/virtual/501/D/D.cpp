#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, s; cin >> n >> k >> s;
    if (s < k || k * (n - 1) < s) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> ans = { 1 };
    int q = s / k, r = s % k;
    for (int i = 0; i < k; i++) {
        int x = ans.back();
        int p = i < r ? 1 : 0;
        i & 1 ? x -= (q + p) : x += (q + p);
        ans.push_back(x);
    }
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}