#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    vector<int> ans(n, 1);
    int x = 1;
    for (int i = 1; i < n; i++) {
        int cnt = b[i] - b[i - 1];
        int j = i - cnt;
        if (j >= 0) {
            ans[i] = ans[j];
        }
        else {
            ans[i] = ++x;
        }
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

