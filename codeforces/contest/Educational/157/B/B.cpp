#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int ans = 0;
    cout << abs(a[0] - a[n - 1]) + abs(a[n] - a[2 * n - 1]) << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << a[i + n] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
