#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int k, x;
    cin >> k >> x;
    int m = 1LL << k;
    cout << m * x << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
