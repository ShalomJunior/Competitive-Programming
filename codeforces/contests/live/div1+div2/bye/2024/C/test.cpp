#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    set<int> s;
    int call = 0;
    function<void(int, int)> go = [&](int l, int r) {
        call++;
        int len = r - l + 1;
        if (l > r || len < k) return;
        int mid = (l + r) / 2;
        if (len & 1) {
            s.insert(mid);
            cerr << mid << " " << l << " " << r << endl;
            go(l, mid - 1);
            go(mid + 1, r);
        }
        else {
            go(l, mid);
            go(mid + 1, r);
        }
        };
    go(l, r);
    cout << "call " << call << endl;
    for (auto& c : s) cerr << c << " ";
    cerr << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

