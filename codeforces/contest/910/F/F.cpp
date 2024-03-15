#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> d(q);
    for (auto& c : d) cin >> c;
    for (int i = 1; i < n; i++) {
        cout << i << " " << i + 1 << endl;
    }
    for (int i = 0; i < q; i++) {
        if ((i == 0 && d[i] == n - 1) || (i && d[i - 1] == d[i])) {
            cout << -1 << " " << -1 << " " << -1 << endl;
            continue;
        }
        cout << n << " " << (i == 0 ? n - 1 : d[i - 1]) << " " << d[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
