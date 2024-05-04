#include <bits/stdc++.h>
using namespace std;

const int L = 26;
void solve() {
    int n; string s; cin >> n >> s;
    vector<vector<int>> cnt(n, vector<int>(L));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < L; j++) {
            cnt[i][j] = (i ? cnt[i - 1][j] : 0);
        }
        cnt[i][s[i] - 'a']++;
    }
    int ans = 1e9;
    function<void(int, int, int, int)> go = [&](int cost, int c, int l, int r) {
        if (l == r) { ans = min(ans, cost + (s[l] - 'a' == c ? 0 : 1)); return; }
        int mid = (l + r) / 2, seg = r - l + 1;
        int d1 = cnt[mid][c] - (l ? cnt[l - 1][c] : 0), d2 = cnt[r][c] - cnt[mid][c];
        go(cost + seg / 2 - d1, c + 1, mid + 1, r);
        go(cost + seg / 2 - d2, c + 1, l, mid);
        };
    go(0, 0, 0, n - 1);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}