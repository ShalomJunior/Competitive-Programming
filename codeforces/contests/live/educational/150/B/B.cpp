#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q; cin >> q;
    int L = -1, R = 1e9, F;
    string ans;
    bool can = true;
    for (int i = 0; i < q; i++) {
        int n; cin >> n;
        if (!i) F = n;
        if (n >= L && n <= R) { L = n; ans += '1'; }
        else {
            if (can && n <= F) {
                L = n, R = F;
                ans += '1';
                can = false;
            }
            else ans += '0';
        }
    }
    cout << ans << endl;
}

/*
1111000000010000000
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}