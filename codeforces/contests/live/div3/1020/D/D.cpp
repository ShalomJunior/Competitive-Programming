#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) cin >> b[i];
    vector<int> L(m + 1);
    for (int i = 1, j = 1; i <= m; i++, j++) {
        while (j <= n && a[j] < b[i]) j++;
        L[i] = j;
    }
    vector<int> R(m + 2, n + 1);
    for (int i = m, j = n; i >= 0; i--, j--) {
        while (j > 0 && a[j] < b[i]) j--;
        R[i] = j;
    }
    if (L[m] <= n) {
        cout << 0 << endl;
        return;
    }
    int ans = INF;
    for (int i = 1; i <= m; i++) {
        if (L[i - 1] < R[i + 1]) {
            ans = min(ans, b[i]);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
