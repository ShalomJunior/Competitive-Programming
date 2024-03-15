#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> x(n + 1), y(n + 1);
    x[0] = y[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (x[i - 1] || y[i - 1]) {
            x[i] = y[i] = 1;
        }
        if (a[i] == '1')x[i] = 0;
        if (b[i] == '1')y[i] = 0;
        if (x[i] == 0 && y[i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << (y[n] ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}