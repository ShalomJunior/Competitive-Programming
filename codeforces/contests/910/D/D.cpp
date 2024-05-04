#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, map<int, int>> h;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int x = a, e = 0;
        while (x % 2 == 0) x /= 2, e++;
        ans += h[x][a - e];
        h[x][a - e]++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
