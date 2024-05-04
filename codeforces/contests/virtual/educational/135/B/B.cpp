#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n & 1) {
        cout << "1 2 3 ";
        for (int i = 4; i + 1 < n - 1; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        cout << n - 1 << " " << n << endl;
    }
    else {
        for (int i = n - 2; i > 0; i--) cout << i << " ";
        cout << n - 1 << " " << n << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
