#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string x, y;
    cin >> n >> x >> y;
    int l1 = 0, r1 = n - 1;
    while (l1 < n && x[l1] != '*') l1++;
    while (r1 >= 0 && x[r1] != '*') r1--;
    int l2 = 0, r2 = n - 1;
    while (l2 < n && y[l2] != '*') l2++;
    while (r2 >= 0 && y[r2] != '*') r2--;
    if (l1 > r1) {
        cout << r2 - l2 << endl;
    }
    else if (l2 > r2) {
        cout << r1 - l1 << endl;
    }
    else {
        int ans = r1 - l1 + r2 - l2;
        if (max(l1, l2) <= min(r1, r2)) {}
        else ans += max(l1, l2) - min(r1, r2);
        ans++;
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
