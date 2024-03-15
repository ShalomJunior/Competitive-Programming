#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    if (n == m) {
        int i;
        for (i = 0; i < n; i++) {
            if (a[i] != b[i])break;
        }
        if (i == n) {
            cout << 0 << endl;
            return;
        }
        int k = n - 1 - i;
        cout << 9 * k + (abs(a[i] - b[i])) << endl;;
    }
    else {
        if (n < m) {
            swap(a, b);
            swap(n, m);
        }
        cout << 9 * (n - 1) + (a[0] - '0') << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}