#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto& x : c) cin >> x;
    int cnt = count(c.begin(), c.end(), 1);
    if (cnt != 1) {
        cout << "NO" << endl;
        return;
    }
    int p = find(c.begin(), c.end(), 1) - c.begin();
    rotate(c.begin(), c.begin() + p, c.end());
    for (int i = 0; i + 1 < n; i++) {
        if (c[i + 1] - c[i] > 1) {
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
