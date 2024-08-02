#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 1e9;
    vector<bool> l(n + 2);
    l[0] = true;
    for (int i = 1; i <= n; i++) {
        if (l[i - 1]) {
            if (a[i - 1] <= a[i]) {
                l[i] = true;
            }
        }
    }
    vector<bool> r(n + 2);
    r[n + 1] = true;
    for (int i = n; i > 0; i--) {
        if (r[i + 1]) {
            if (a[i] <= a[i + 1]) {
                r[i] = true;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (l[i] && r[i + 1]) {
            if (a[i] <= a[i + 1] || a[n] <= a[1]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
