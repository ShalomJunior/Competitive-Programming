#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k & 1) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i += 2) {
            cout << i << " " << i + 1 << endl;
        }
    }
    else {
        if (k % 4) {
            cout << "YES" << endl;
            for (int i = 4; i <= n; i += 4) {
                cout << i - 1 << " " << i << endl;
            }
            for (int i = 2; i <= n; i += 4) {
                cout << i << " " << i - 1 << endl;
            }
        }
        else cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}