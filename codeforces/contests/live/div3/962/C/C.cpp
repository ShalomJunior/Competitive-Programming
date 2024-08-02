#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    a = "#" + a;
    b = "#" + b;
    vector<vector<int>> pref(n + 1, vector<int>(N));
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        pref[i][a[i] - 'a']++;
        pref[i][b[i] - 'a']--;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int j = 0; j < N; j++) {
            int cnt = pref[r][j] - pref[l - 1][j];
            if (cnt > 0) ans += cnt;
            ans += cnt;
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
