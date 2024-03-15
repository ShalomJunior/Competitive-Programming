#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int neg = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        (a < 0) ? neg++ : pos++;
    }
    int need = (n + 1) / 2;
    if (pos < need) {
        int ans = need - pos;
        neg -= ans; pos += ans;
        cout << ((neg & 1) ? ans + 1 : ans) << endl;
    }
    else cout << ((neg & 1) ? 1 : 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}