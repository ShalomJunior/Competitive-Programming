#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, n; cin >> x >> y >> n;
    vector<int> a(n);
    a[0] = x, a[n - 1] = y;
    if (y - x < n * (n - 1) / 2) {
        cout << -1 << endl;
        return;
    }
    for (int i = n - 2; i > 0; i--) {
        a[i] = a[i + 1] - (n - 1 - i);
    }
    for (auto& c : a) cout << c << " ";
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}