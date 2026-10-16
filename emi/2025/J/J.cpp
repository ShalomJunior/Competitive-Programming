#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int n) {
    return n * (n + 1) / 2;
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << f(r) - f(l) + l << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}