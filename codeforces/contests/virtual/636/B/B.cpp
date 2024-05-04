#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n == 2 || (n / 2) & 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) cout << 2 * (i + 1);
        else cout << (2 * (i % (n / 2)) + 1 + (i == n - 1 ? n / 2 : 0));
        cout << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}