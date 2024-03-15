#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int need = (a < x ? x - a : 0) + (b < y ? y - b : 0);
    cout << (need <= c ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}