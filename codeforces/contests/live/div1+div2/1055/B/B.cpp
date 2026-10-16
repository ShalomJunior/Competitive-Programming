#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;
    int dr = abs(rk - rd);
    int dc = abs(ck - cd);
    int r = 0;
    if (rk < rd) {
        r = rk;
    }
    else if (rk == rd) {
        r = max(rk, n - rk);
    }
    else {
        r = n - rk;
    }
    int c = 0;
    if (ck < cd) {
        c = ck;
    }
    else if (rk == rd) {
        c = max(ck, n - ck);
    }
    else {
        c = n - ck;
    }
    if (dr == 0) {
        cout << c + dc;
    }
    else if (dc == 0) {
        cout << r + dr;
    }
    else {
        int ans = max(dc + c, dr + r);
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
