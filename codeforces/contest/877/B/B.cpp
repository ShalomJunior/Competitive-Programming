#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        h[c] = i + 1;
        a[i] = c;
    }
    if (is_sorted(a.begin(), a.end())) {
        cout << 2 << " " << n << endl;
        return;
    }
    reverse(a.begin(), a.end());
    if (is_sorted(a.begin(), a.end())) {
        cout << 1 << " " << n - 1 << endl;
        return;
    }
    int mn = min({ h[1], h[2], h[n] });
    int mx = max({ h[1], h[2], h[n] });
    if (h[n] == mn) {
        cout << h[n] << " " << min(h[1], h[2]) << endl;
    }
    else if (h[n] == mx) {
        cout << max(h[1], h[2]) << " " << h[n] << endl;
    }
    else {
        cout << h[1] << " " << h[1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}