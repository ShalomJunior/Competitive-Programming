#include <bits/stdc++.h>
#define int long long
using namespace std;

const int H = 24;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            if (a[i] > a[i - 1]) {
                b[i] = b[i - 1] + a[i] - a[i - 1];
            }
            else {
                b[i] = b[i - 1] + (H - a[i - 1]) + a[i];
            }
        }
        else {
            b[i] = a[i];
        }
    }
    int z = min(k, n - 1);
    int ans = max(b[z] - 1, 0LL);
    for (int i = 1; i < n; i++) {
        int j = min(i + k, n - 1);
        ans = max(ans, b[j] - b[i - 1] - 1);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}