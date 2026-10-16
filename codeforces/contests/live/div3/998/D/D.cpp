#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            int mn = min(i - 1 >= 0 ? a[i - 1] : 0, a[i]);
            mn = min(mn, a[i] - a[i + 1]);
            if (a[i] - mn <= a[i + 1]) {
                a[i] -= mn;
                a[i - 1] -= mn;
            }
            else {
                cout << "NO" << endl;
                return;
            }
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
