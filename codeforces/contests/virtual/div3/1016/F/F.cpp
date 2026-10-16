#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> c(n);
    for (auto& s : c) cin >> s;
    vector<vector<string>> b(m, vector<string>(n));
    vector<int> match(n);
    int mx = 0;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
            match[j] += b[i][j] == c[j];
            cnt += b[i][j] == c[j];
        }
        mx = max(mx, cnt);
    }
    if (*min_element(match.begin(), match.end()) == 0) {
        cout << -1 << endl;
        return;
    }
    int ans = n;
    if (mx < n) {
        ans += (n - mx) * 2;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}