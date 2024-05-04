#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < 0) {
            cout << "NO" << endl;
            return;
        }
        int x = a[i - 1];
        int y = a[i] / 2;
        int z = a[i + 1];
        a[i - 1] -= min({ x, y, z });
        a[i] -= 2 * min({ x, y, z });
        a[i + 1] -= min({ x, y, z });
    }
    for (int i = 0;i < n; i++) {
        if (a[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}