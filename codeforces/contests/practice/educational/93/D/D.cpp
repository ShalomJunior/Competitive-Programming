#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    vector<int> a(n), pre(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        pre[i] = a[i] + (i ? pre[i - 1] : 0);
    }
    long long ans = 0;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        h[(i ? pre[i - 1] : 0) - (i - 1)]++;
        ans += h[pre[i] - i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
