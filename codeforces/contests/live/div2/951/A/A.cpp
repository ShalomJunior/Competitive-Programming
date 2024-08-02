#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int mx = 1e9;
    for (int i = 0; i + 1 < n; i++) {
        mx = min(mx, max(a[i], a[i + 1]));
    }
    cout << mx - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
