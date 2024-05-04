#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    vector<bool> f(26, false);
    for (auto& c : s) {
        if (!f[c - 'A']) {
            f[c - 'A'] = true;
            ans += 2;
        }
        else ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}