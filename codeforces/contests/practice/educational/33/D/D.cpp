#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    vector<int> mn(n + 1);
    for (int i = n; i > 0; i--) {
        if (pref[i] > d) {
            cout << -1 << endl;
            return;
        }
        mn[i] = min(d - pref[i], i == n ? INF : mn[i + 1]);
    }
    int ans = 0;
    int used = 0;
    int money = 0;
    for (int i = 1; i <= n; i++) {
        money += a[i];
        if (a[i] == 0) {
            if (money < 0) {
                money += mn[i] - used;
                used = mn[i];
                ans++;
                if (money < 0) {
                    cout << -1 << endl;
                    return;
                }
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