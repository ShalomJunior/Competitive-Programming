#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e15;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    vector<int> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = max(a[i], b[i]);
        if (i + 1 < n) x[i] = max(x[i], x[i + 1]);
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + x[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}