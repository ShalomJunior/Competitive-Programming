#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    int ans = 0;
    int L = 0, R = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < 2 * a[i + 1])R++;
        else {
            int cnt = R - L + 1;
            if (cnt > k) ans += (cnt - k);
            L = R = i + 1;
        }
    }
    int cnt = R - L + 1;
    if (cnt > k) ans += (cnt - k);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}