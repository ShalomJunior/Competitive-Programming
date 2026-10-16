#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int j = 2;
    int cnt = 0;
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        if (i % 2 == 0) {
            if (cnt > 1) break;
            j = max(j, i);
            cnt = 0;
            while (j + k - i <= n) {
                if (a[j] != i / 2) {
                    cout << ans << endl;
                    return;
                }
                cnt++;
                j++;
            }
            ans++;
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
