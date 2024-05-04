#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<int> pref(m + 1), suff(m + 1);
    pref[0] = -1; suff[0] = n;
    auto L = [&] {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[j]) {
                pref[++j] = i;
            }
            if (j == m) return;
        }
        };
    auto R = [&] {
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == t[j]) {
                suff[m - j] = i;
                j--;
            }
            if (j == -1) return;
        }
        };
    L(), R();
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        int l = pref[i], r = suff[m - i];
        if (l < r) ans = max(ans, r - l - 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}