#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n < 4) {
        cout << -1 << endl;
        return;
    }
    if (n == 4) {
        cout << "2 4 1 3" << endl;
        return;
    }
    if (n & 1) {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        cout << n - 3 << " " << n - 1 << " ";
        for (int i = n - 5; i > 1; i -= 2) {
            cout << i << " ";
        }
    }
    else {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        cout << n - 4 << " " << n << " ";
        cout << n - 2 << " ";
        for (int i = n - 6; i > 0; i -= 2) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}