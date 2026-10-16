#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, a;
    cin >> x >> y >> a;
    int s = x + y;
    int r = a % s;
    cout << (x > r ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
