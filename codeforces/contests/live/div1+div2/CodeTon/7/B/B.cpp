#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    vector<int> a = { 1 };
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) a.back()++;
        else a.push_back(1);
    }
    int m = a.size();
    int ans = 0;
    for (int i = s[0] == 'A' ? 0 : 1; i < n; i += 2) {
        if (i + 1 < m) {
            ans += a[i] + a[i + 1] - 1;
            if (i - 2 >= 0) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}