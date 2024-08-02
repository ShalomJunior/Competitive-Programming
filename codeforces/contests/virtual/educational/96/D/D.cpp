#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int i = 0;
    int j = 0;
    int ans = 0;
    vector<bool> f(n);
    while (i < n - 1) {
        if (s[i] == s[i + 1]) {
            f[i] = true;
            ans++;
            int k = j;
            while (j < n && (f[j] || s[j] == s[k])) j++;
        }
        i = max(i + 1, j);
    }
    int cnt = 0;
    while (j < n) cnt += !f[j++];
    cnt++;
    cout << ans + cnt / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
