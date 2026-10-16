#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int s = 0;
    vector<int> b(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        b[i] = !b[i + 1];
        b[i] ? s += a[i] : s -= a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, v;
        cin >> l >> r >> v;
        l--;
        r--;
        int len = r - l + 1;
        if (len & 1) {
            b[l] ? s += v : s -= v;
        }
        cout << s << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
