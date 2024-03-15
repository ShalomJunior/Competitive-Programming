#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second 
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> a(n + 1);
    vector<Mine> seg(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1], seg[i] = seg[i - 1];
        s[i - 1] == '+' ? a[i]++ : a[i]--;
        seg[i].F = min(seg[i].F, a[i]);
        seg[i].S = max(seg[i].S, a[i]);
    }
    vector<Mine> h(n + 1);
    int m = a[n], M = a[n];
    for (int i = n; i > 0; i--) {
        m = min(m, a[i]); M = max(M, a[i]);
        h[i].F = (a[i - 1] < m ? 0 : a[i - 1] - m);
        h[i].S = (a[i - 1] > M ? 0 : M - a[i - 1]);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        auto ans = seg[l - 1];
        Mine rem = { a[l - 1], a[l - 1] };
        if (r != n) {
            rem.F -= h[r + 1].F;
            rem.S += h[r + 1].S;
        }
        ans.F = min(ans.F, rem.F);
        ans.S = max(ans.S, rem.S);
        cout << ans.S - ans.F + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}