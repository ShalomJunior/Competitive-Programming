#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int r = n - i - 1;
        if (i % 2 == 0 && r % 2 == 0)
            ans = max(ans, a[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}