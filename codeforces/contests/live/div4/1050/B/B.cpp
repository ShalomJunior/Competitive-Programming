#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int v;
    int ans = n + m;
    for (int i = 0; i < ans; i++) cin >> v;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
