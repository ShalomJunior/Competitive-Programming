#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int tot = accumulate(a.begin(), a.end(), 0LL);
    int q = tot / n;
    int have = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < q) {
            if (have < q - a[i]) {
                cout << "NO" << endl;
                return;
            }
            else have -= q - a[i];
        }
        else have += a[i] - q;
    }
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
