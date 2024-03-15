#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<vector<int>> cnt(n, vector<int>(N));
    cnt[0][s[0] - 'a']++;
    for (int i = 1; i < n; i++) {
        cnt[i] = cnt[i - 1];
        cnt[i][s[i] - 'a']++;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int c = cnt[r][i] - (l == 0 ? 0 : cnt[l - 1][i]);
            ans += (i + 1) * c;
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}