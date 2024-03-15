#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n <= 6 || n == 9) cout << "NO" << endl;
    else if (n % 3) {
        cout << "YES" << endl;
        cout << 1 << " " << 2 << " " << n - 3 << endl;
    }
    else {
        cout << "YES" << endl;
        cout << 1 << " " << 4 << " " << n - 5 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
