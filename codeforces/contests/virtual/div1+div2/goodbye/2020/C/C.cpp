#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    auto work = [&](int i) {
        int l = max(i - 2, 0);
        int r = min(i + 2, n - 1);
        for (char c = 'a'; c <= 'z'; c++) {
            bool f = true;
            for (int j = l; j <= r; j++) {
                if (s[j] == c) {
                    f = false;
                }
            }
            if (f) {
                s[i] = c;
                return;
            }
        }
        assert(false);
        };
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i] == s[i + 1]) {
            work(i + 1);
            ans++;
        }
        if (i + 2 < n && s[i] == s[i + 2]) {
            work(i + 2);
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}