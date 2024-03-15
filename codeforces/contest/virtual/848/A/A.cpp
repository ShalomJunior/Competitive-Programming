#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& c : v)cin >> c;

    int ans = accumulate(v.begin(), v.end(), 0);
    bool b = true;
    for (int i = 0; i < n - 1; i++) {
        b &= (v[i] > 0 && v[i + 1] > 0);
        if (v[i] < 0 && v[i + 1] < 0) {
            cout << ans + 4 << endl;
            return;
        }
    }

    cout << ((b) ? ans - 4 : ans) << endl;
}
int main() {
    int t; cin >> t;
    while (t--)solve();
}