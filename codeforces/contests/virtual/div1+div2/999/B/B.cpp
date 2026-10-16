#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    vector<int> L(n);
    for (int i = 1; i < n; i++) {
        L[i] = a[i - 1] == a[i] ? a[i] : L[i - 1];
    }
    vector<int> R(n);
    for (int i = n - 2; i >= 0; i--) {
        R[i] = a[i] == a[i + 1] ? max(a[i], R[i + 1]) : R[i + 1];
    }
    auto check = [&](int x, int y) {
        return x > 0 && 4LL * x * x > y * y;
        };
    for (int i = 0; i + 1 < n; i++) {
        int y = a[i + 1] - a[i];
        if (i - 1 >= 0 && check(L[i - 1], y)) {
            cout << L[i - 1] << " " << L[i - 1] << " " << a[i] << " " << a[i + 1] << endl;
            return;
        }
        if (i + 2 < n && check(R[i + 2], y)) {
            cout << R[i + 2] << " " << R[i + 2] << " " << a[i] << " " << a[i + 1] << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}