#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    deque<int> o, e;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] & 1 ? o.push_back(a[i]) : e.push_back(a[i]);
    }
    if (o.empty() || e.empty()) {
        cout << 0 << endl;
        return;
    }
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    int ans = 0;
    int boss = o.back();
    while (!e.empty()) {
        int u = e.front();
        e.pop_front();
        if (u < boss) {
            boss += u;
            ans++;
        }
        else {
            ans += e.size() + 2;
            break;
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
