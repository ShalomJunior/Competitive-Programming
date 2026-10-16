#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int k = 0; k < n; k++) {
        bool b = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                b &= __gcd(a[i] + k, a[j] + k) == 1;
            }
        }
        if (b) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
