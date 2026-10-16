#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> o, e;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        c & 1 ? o.push_back(c) : e.push_back(c);
    }
    sort(o.rbegin(), o.rend());
    sort(e.rbegin(), e.rend());
    if (o.empty()) {
        cout << e.front();
    }
    else if (e.empty()) {
        cout << o.front();
    }
    else {
        int ans = o.front();
        o.pop_front();
        int k = min(o.size(), e.size());
        while (k--) {
            ans += o.front() + e.front() - 1;
            o.pop_front();
            e.pop_front();
        }
        while (!o.empty()) {
            ans += o.front() - 1;
            o.pop_front();
        }
        while (!e.empty()) {
            ans += e.front();
            e.pop_front();
        }
        cout << ans;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
