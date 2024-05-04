#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> next(n + 1), back(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        next[i] = back[i + 1];
        if (a[i] > next[i]) {
            cout << "NO" << endl;
            return;
        }
        back[i] = next[i] - a[i];
        if (i && next[i] && !back[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << (next[0] >= 0 && back[0] == 0 ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}