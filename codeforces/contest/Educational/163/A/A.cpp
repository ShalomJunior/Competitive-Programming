#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n / 2; i++) {
        cout << "A" << "BB";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
