#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int H, n; cin >> H >> n;
    vector<int> a(n);
    int sum = 0, m = INF;
    bool b = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = min(m, sum += a[i]);
        b |= (H + sum <= 0);
    }
    if (!b && sum >= 0) {
        cout << -1 << endl;
        return;
    }
    int sup = (-m < H ? H + m : 0);
    int rounds = sup / -sum;
    int ans = rounds * n;
    H += rounds * sum;
    if (H > 0) {
        for (int i = 0; i < 2; i++) {
            bool over = false;
            for (int j = 0, cum = 0; j < n; j++) {
                cum += a[j];
                if (H + cum <= 0) {
                    ans += j + 1;
                    over = true;
                    break;
                }
            }
            if (over) break;
            else {
                H += sum;
                ans += n;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}