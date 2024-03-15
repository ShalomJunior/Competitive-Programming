#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        i ? m &= a[i] : m = a[i];
    }
    int i = 0;
    for (int c = a[0]; i < n; i++) {
        c &= a[i];
        if (c == m)break;
    }
    int ans = 1; ++i;
    while (i < n) {
        for (int c = a[i]; i < n; i++) {
            c &= a[i];
            if (!c) { ans++; break; }
        }
        i++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}