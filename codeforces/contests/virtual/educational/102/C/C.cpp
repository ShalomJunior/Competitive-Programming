#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= 2 * k - n - 1; i++) {
        cout << i << " ";
    }
    for (int i = k; i > 2 * k - n - 1; i--) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}