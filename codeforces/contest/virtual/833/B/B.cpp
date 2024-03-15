#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int dig = 0, mx = 0;
        vector<int> cnt(10);
        for (int j = 0; j < 100 && i + j < n; j++) {
            int d = s[i + j] - '0';
            if (!cnt[d]) dig++;
            cnt[d]++;
            mx = max(mx, cnt[d]);
            if (mx <= dig) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}