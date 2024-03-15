#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; string x, s;
    cin >> n >> m >> x >> s;
    int ans = 0;
    while (x.find(s) == -1) {
        ans++;
        x += x;
        if (x.size() > 500) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
