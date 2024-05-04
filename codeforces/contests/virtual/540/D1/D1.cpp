#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for (auto& c : a) {
        cin >> c;
        sum += c;
    }
    if (sum < m) {
        cout << -1 << endl;
        return;
    }
    sort(a.rbegin(), a.rend());
    int L = 1, R = n;
    auto go = [&](int mid) {
        int ans = 0;
        for (int i = 0, sub = 0; i < n; i++) {
            if (i && i % mid == 0) sub++;
            ans += max(0LL, a[i] - sub);
        }
        return ans >= m;
        };
    while (L < R) {
        int mid = (L + R) / 2;
        go(mid) ? R = mid : L = mid + 1;
    }
    cout << L << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}