#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int j = 0;
    while (j < n && '0' <= s[j] && s[j] <= '9') j++;
    for (int i = j; i < n; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            cout << "NO" << endl;
            return;
        }
    }
    bool x = is_sorted(s.begin(), s.begin() + j);
    bool y = is_sorted(s.begin() + j, s.end());
    cout << (x & y ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
