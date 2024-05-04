#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i]) cnt++;
        if (!a[i] || i == 2 * n - 1) {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}