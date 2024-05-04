#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int x = min(a, b), y = max(a, b);
    int mid = y - (x - 1);
    if (c > 2 * (mid - 1) || mid <= x) cout << -1;
    else {
        cout << (c < mid ? c + mid - 1 : c - mid + 1);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}