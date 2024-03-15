#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n & 1) { cout << ((n == 1) ? 1 : -1) << endl; return; }
    for (int i = 1; i <= n / 2; i++) {
        cout << 2 * i << " " << 2 * i - 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}