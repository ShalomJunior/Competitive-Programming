#include <bits/stdc++.h>

using namespace std;

void solve() {
    int  w, h, n;
    cin >> w >> h >> n;
    int cards = 1;
    while (w % 2 == 0)
        cards *= 2, w /= 2;

    while (h % 2 == 0)
        cards *= 2, h /= 2;

    (cards < n) ? cout << "NO\n" : cout << "YES\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}