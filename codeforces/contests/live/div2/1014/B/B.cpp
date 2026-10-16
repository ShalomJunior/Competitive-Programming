#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            x += b[i] == '0';
            y += a[i] == '0';
        }
        else {
            x += a[i] == '0';
            y += b[i] == '0';
        }
    }
    int l = (n + 1) / 2;
    int r = n / 2;
    int ans = min(x, l) + min(y, r);
    cout << (ans >= n ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
