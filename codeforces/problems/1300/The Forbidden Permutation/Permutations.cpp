#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

void solve() {
    cout << "Solving" << endl;
    int n, m, d; cin >> n >> m >> d;
    unordered_map<int, int> pos;
    for (int i = 1; i <= n; ++i) {
        int p; cin >> p;
        pos[p] = i;
    }

    for (auto [k, v] : pos) {
        cout << k << "->" << v << endl;
    }
    vector<int> a(n), idx(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        idx[i] = pos[a[i]];
        cout << "idx = " << idx[i] << endl;
    }

    for (int i = 0; i < m - 1; i++) {
        int l = idx[i], r = idx[i + 1];
        if (l > r || r > l + d) {
            cout << 0 << endl;
            return;
        }
    }

    int ans = INF;
    for (int i = 0; i < m - 1; i++) {
        cout << "in " << idx[i] << " " << idx[i + 1] << endl;
        ans = min(ans, idx[i + 1] - idx[i]);
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}