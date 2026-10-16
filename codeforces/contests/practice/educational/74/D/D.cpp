#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    auto f = [&](int& j, char c) {
        int cnt = 0;
        while (j < n && s[j] == c) cnt++, j++;
        return cnt;
        };
    vector<int> a;
    for (int i = 0; i < n; ) {
        for (auto c : { 'A', 'B' }) {
            int cnt = f(i, c);
            if (cnt) a.push_back(cnt);
        }
    }
    int ans = 1LL * n * (n - 1) / 2;
    int m = a.size();
    for (int i = 1; i < m; i++) {
        ans -= a[i - 1];
        if (a[i] > 1) ans -= a[i] - 1;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
