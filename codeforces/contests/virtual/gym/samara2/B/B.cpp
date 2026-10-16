#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    int ok = 0;
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) ok = 1;
        else {
            x < 0 ? neg.push_back(-x) : pos.push_back(x);
        }
    }
    reverse(neg.begin(), neg.end());
    int ans = 0;
    int n1 = pos.size();
    for (int i = 0; i < n1; i++) {
        if (pos[i] <= t) {
            int r = max(t - 2 * pos[i], 0LL);
            auto it = upper_bound(neg.begin(), neg.end(), r);
            int cnt = it - neg.begin();
            ans = max(ans, i + 1 + cnt);
        }
    }
    int n2 = neg.size();
    for (int i = 0; i < n2; i++) {
        if (neg[i] <= t) {
            int r = max(t - 2 * neg[i], 0LL);
            auto it = upper_bound(pos.begin(), pos.end(), r);
            int cnt = it - pos.begin();
            ans = max(ans, i + 1 + cnt);
        }
    }
    cout << ans + ok << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
