#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int x = n - 2 * (k - 1);
    if (x > 0 && x % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++)
            cout << 2 << " ";
        cout << n - 2 * (k - 1) << endl;
        return;
    }
    int y = n - (k - 1);
    if (y > 0 && y & 1) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++)
            cout << 1 << " ";
        cout << n - (k - 1) << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}