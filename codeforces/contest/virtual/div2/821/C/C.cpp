#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<bool> b(n);
    stringstream ss;
    if (a[0] % 2 == a[n - 1] % 2) {
        for (int i = n - 2; i >= 0; i--) {
            if (!b[i] && a[i] % 2 == a[n - 1] % 2) {
                b[i] = true;
                ss << i + 1 << " " << n << endl;
            }
        }
        for (int i = 1; i < n; i++) {
            if (!b[i] && a[i] % 2 != a[0] % 2) {
                b[i] = true;
                ss << 1 << " " << i + 1 << endl;
            }
        }
    }
    else {
        for (int i = 1; i < n; i++) {
            if (!b[i] && a[i] % 2 != a[0] % 2) {
                b[i] = true;
                ss << 1 << " " << i + 1 << endl;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (!b[i] && a[i] % 2 == a[0] % 2) {
                b[i] = true;
                ss << i + 1 << " " << n << endl;
            }
        }
    }
    int m = count(b.begin(), b.end(), true);
    cout << m << endl;
    cout << ss.str() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}