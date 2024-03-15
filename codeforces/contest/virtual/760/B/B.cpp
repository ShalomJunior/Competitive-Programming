#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> s(n - 2);
    for (auto& c : s) cin >> c;
    string ans;
    bool b = false;
    for (int i = 0; i < n - 2; i++) {
        if (i && s[i][0] != s[i - 1][1]) {
            ans += s[i - 1][1];
            b = true;
        }
        ans += s[i][0];
    }
    ans += s.back()[1];
    if (ans.size() != n) ans = 'a' + ans;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}