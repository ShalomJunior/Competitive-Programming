#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> o, e;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x & 1 ? o.push_back(x) : e.push_back(x);
    }
    int se = accumulate(e.begin(), e.end(), 0LL);
    sort(o.begin(), o.end());
    if (!o.empty()) {
        int ans = o.back() + se;
        o.pop_back();
        while (o.size() > 1) {
            o.pop_front();
            ans += o.back();
            o.pop_back();
        }
        cout << ans;
    }
    else {
        cout << 0;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
