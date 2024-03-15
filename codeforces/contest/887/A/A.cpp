#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << 0 << endl;
            return;
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n - 1; i++) {
        int diff = a[i + 1] - a[i];
        if (diff & 1) ans = min(ans, (diff + 1) / 2);
        else ans = min(ans, diff / 2 + 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}