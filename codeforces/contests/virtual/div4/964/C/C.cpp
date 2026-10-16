#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    int ends = 0;
    bool f = false;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l - ends >= s) f = true;
        ends = r;
    }
    if (m - ends >= s) f = true;
    cout << (f ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}