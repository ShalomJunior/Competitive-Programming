#include <bits/stdc++.h>
#define int long long
using namespace std;

bool is(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    // Bullshit bullshit
    int x, k;
    cin >> x >> k;
    if (x > 1 && k > 1) {
        cout << "NO" << endl;
        return;
    }
    int s = 0;
    for (int i = 0; i < k; i++) s = (s * 10) + x;
    cout << (is(x) ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}