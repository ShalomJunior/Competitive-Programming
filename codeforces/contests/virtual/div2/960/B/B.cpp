#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> a(n, 1);
    for (int i = y - 1; i >= 0; i--) {
        if ((y - i) & 1) a[i] = -1;
    }
    for (int i = x + 1; i < n; i++) {
        if ((i - x - 1) % 2 == 0) a[i] = -1;
    }
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}