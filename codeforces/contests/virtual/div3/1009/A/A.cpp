#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    cout << (min({ l, r, d, u }) == max({ l , r, d, u }) ? "Yes" : "No") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}