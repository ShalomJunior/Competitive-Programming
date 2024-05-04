#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(a.begin(), a.end(), a[i] + 6);
        int cnt = it - (a.begin() + i);
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}