#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int c) {
    int ans = 0;
    if (b <= a && c <= a || b >= a && c >= a) {
        ans += min(abs(a - b), abs(a - c));
    }
    return ans;
}

void solve() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int ans = f(xa, xb, xc) + f(ya, yb, yc) + 1;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}