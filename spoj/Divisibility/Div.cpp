#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        if (i % x == 0 && i % y != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}