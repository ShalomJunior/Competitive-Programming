#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<bool> l(n), r(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) l[i] = l[i - 1];
        if (a[i] == '.' || b[i] == '.') l[i] = true;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) r[i] = r[i + 1];
        if (a[i] == '.' || b[i] == '.') r[i] = true;
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == b[i] && a[i] == '.') {
            if (a[i - 1] == a[i + 1] && a[i - 1] == 'x' && l[i - 1] && r[i + 1]) ans++;
            else if (b[i - 1] == b[i + 1] && b[i - 1] == 'x' && l[i - 1] && r[i + 1]) ans++;
            else {}
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
