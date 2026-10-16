#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> h(n);
    for (int k = 1; k * k <= n; k++) {
        h[k].resize(n + 1);
        for (int j = n; j > 0; j--) {
            h[k][j] = 1LL + (j + a[j] + k > n ? 0 : h[k][j + a[j] + k]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int p, k;
        cin >> p >> k;
        if (k * k <= n) {
            cout << h[k][p] << endl;
        }
        else {
            int ans = 0;
            while (p <= n) {
                p += a[p] + k;
                ans++;
            }
            cout << max(ans, 1LL) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
