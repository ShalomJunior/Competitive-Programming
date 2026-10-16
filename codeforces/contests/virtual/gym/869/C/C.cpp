#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<bool> b(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            b[i] = true;
            if (i - 1 >= 0) b[i - 1] = true;
            if (i + 1 < n) b[i + 1] = true;
        }
    }
    int i = 0;
    int ans = 0;
    while (i < n) {
        if (b[i]) {
            i++;
            continue;
        }
        int len = 0;
        while (i + len < n && !b[i + len]) len++;
        i += len + 1;
        ans += (len + 2) / 3;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
