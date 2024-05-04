#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int x = 0, y = 0;
    while (n % 2 == 0) { x++; n /= 2; }
    while (n % 3 == 0) { y++; n /= 3; }
    if (n != 1 || x > y) {
        cout << -1 << endl;
        return;
    }
    cout << (x >= y ? x : 2 * y - x) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}