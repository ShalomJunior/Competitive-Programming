#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        h[a]++;
    }
    int q; cin >> q;
    while (q--) {
        int s, p; cin >> s >> p;
        int delta = s * s - 4 * p;
        if (delta < 0) {
            cout << 0 << " ";
            continue;
        }
        int x1 = (s - sqrt(delta)) / 2, x2 = (s + sqrt(delta)) / 2;
        if (x1 + x2 != s || x1 * x2 != p) {
            cout << 0 << " ";
            continue;
        }
        cout << (x1 != x2 ? h[x1] * h[x2] : h[x1] * (h[x1] - 1) / 2) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}