#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& s : a) cin >> s;
    string ans = a[0];
    for (int i = 1; i < n; i++) {
        ans = min(a[i] + ans, ans + a[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}