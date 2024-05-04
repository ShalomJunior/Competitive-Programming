#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = a[i] + (i ? pre[i - 1] : 0);
    }
    int ans = 0;
    for (int i = 0; i <= min(z, k / 2); i++) {
        while (a.size() > k - 2 * i + 2) a.pop_back();
        int m = a.size();
        for (int j = 0; j + 1 < m - 1; j++) {
            int curr = (j ? pre[j - 1] : 0) + (i + 1) * (a[j] + a[j + 1]);
            curr += accumulate(a.begin(), a.begin(), 0);
            ans = max(ans, curr);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
