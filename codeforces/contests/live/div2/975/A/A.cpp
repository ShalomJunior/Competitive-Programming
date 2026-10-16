#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> b(n);
        b[i] = true;
        for (int j = i + 2; j < n; j++) {
            if (!b[j - 1] && a[j] <= a[i]) {
                b[j] = true;
            }
        }
        for (int j = i - 2; j >= 0; j--) {
            if (!b[j + 1] && a[j] <= a[i]) {
                b[j] = true;
            }
        }
        int cnt = count(b.begin(), b.end(), true);
        ans = max(ans, a[i] + cnt);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
