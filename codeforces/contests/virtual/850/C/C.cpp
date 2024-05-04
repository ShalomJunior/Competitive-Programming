#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    sort(a.begin(), a.end());
    long long ans = 0;
    if (a[0] != 1) {
        ans += a[0] - 1;
        a[0] = 1;
    }
    for (int i = 1; i < n; i++) {
        int d = a[i] - a[i - 1];
        if (d > 1) {
            ans += d - 1;
            a[i] = a[i - 1] + 1;
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