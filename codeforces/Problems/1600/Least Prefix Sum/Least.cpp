#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m; cin >> n >> m; m--;
    vector<int> v(n), pref(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pref[i] = (i) ? pref[i - 1] + v[i] : v[i];
    }

    int ans = 0;
    priority_queue<int> pq;
    for (int i = m; i >= 0; i--) {
        while (pref[i] < pref[m]) {
            pref[m] -= 2 * pq.top(); pq.pop();
            ans++;
        }
        if (v[i] > 0)pq.push(v[i]);
    }
    pq = priority_queue<int>();
    for (int i = m + 1; i < n; i++) {
        if (v[i] < 0)pq.push(-v[i]);
        while (pref[i] < pref[m]) {
            pref[i] += 2 * pq.top(); pq.pop();
            ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}