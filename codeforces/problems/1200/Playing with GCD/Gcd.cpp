#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n + 1);
    for (auto& c : a) cin >> c;

    b[0] = a[0];
    b[n] = a[n - 1];
    for (int i = 1; i < n; i++) {
        b[i] = lcm(a[i - 1], a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (gcd(b[i], b[i + 1]) != a[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}