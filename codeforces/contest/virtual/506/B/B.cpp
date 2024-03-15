#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<bool> b(n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] <= 2 * a[i])
            b[i] = true;
    }
    int ans = 0, cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (b[i]) cnt++;
        if (!b[i] || i == n - 2) {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}