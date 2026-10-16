#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, y, r;
    cin >> n >> y >> r;
    int mx = r + y / 2;
    cout << min(n, mx) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
