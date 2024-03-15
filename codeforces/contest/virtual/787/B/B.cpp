#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    if (n == 1) { cout << 0 << endl; return; }
    else if (!a[n - 1]) { cout << -1 << endl; return; }
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        while (a[i] >= a[i + 1]) {
            a[i] /= 2; ans++;
            if (a[i] == 0 && i > 0) {
                cout << -1 << endl;
                return;
            }
        }
        if (a[i] == 0 && i > 0) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}