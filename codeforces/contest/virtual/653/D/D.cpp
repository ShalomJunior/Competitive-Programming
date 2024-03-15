#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x % k]++;
    }
    int M = 0;
    for (auto& [key, val] : h) {
        if (key) M = max(M, k - key + (val - 1) * k);
    }
    cout << (M ? M + 1 : 0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}