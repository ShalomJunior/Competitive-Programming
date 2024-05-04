#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> d(n);
    for (auto& c : d) cin >> c;
    sort(d.begin(), d.end());
    set<int> s;
    for (int i = 0; i < (n + 1) / 2; i++) {
        s.insert(d[i] * d[n - 1 - i]);
    }
    if (s.size() > 1) {
        cout << "-1" << endl;
        return;
    }
    int ans = *s.begin();
    int cnt = 0;
    for (int i = 2; i * i <= ans; i++) {
        if (ans % i == 0) {
            cnt++;
            if (ans / i != i) cnt++;
        }
    }
    cout << (cnt == n ? ans : -1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}