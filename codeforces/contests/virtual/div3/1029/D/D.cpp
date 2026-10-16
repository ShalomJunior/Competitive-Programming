#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> in;
    for (int i = 1; i < n; i++) {
        int u = a[i] - a[0];
        int k = i;
        if (abs(u) % k) {
            cout << "NO" << endl;
            return;
        }
        in.insert(u / k);
    }
    if (in.size() > 1) {
        cout << "NO" << endl;
        return;
    }
    int d = *in.begin();
    int r = a[0] - d;
    if (r % (n + 1)) {
        cout << "NO" << endl;
        return;
    }
    int y = r / (n + 1);
    int x = d + y;
    if (x < 0 || y < 0) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        int u = a[i] - x * (i + 1) - y * (n - (i + 1) + 1);
        if (u != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}