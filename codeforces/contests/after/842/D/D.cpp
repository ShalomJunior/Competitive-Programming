#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    vector<int> pref(n), suf(n);
    for (int i = 0; i < n; i++) {
        pref[i] = (p[i] != i + 1 ? 1 : 0) + (i ? pref[i - 1] : 0);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = (p[i] != i + 1 ? 1 : 0) + (i == n - 1 ? 0 : suf[i + 1]);
    }
    int ans = 1e9;
    for (int i = 0; i < n - 1; i++) {
        int bad = (i ? pref[i - 1] : 0) + (i + 2 < n - 1 ? suf[i + 2] : 0);
        cout << "bad = " << bad << endl;
        if (p[i] != i + 2) bad++;
        if (p[i + 1] != i + 1) bad++;
        cout << "#bad = " << bad << endl;
        ans = min(ans, (bad + 1) / 2);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}