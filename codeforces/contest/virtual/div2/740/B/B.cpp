#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    int n = a + b;
    vector<bool> ans(n + 1);
    auto go = [&](int sa, int sb) {
        int m, M;
        if (a > sa) {
            m = a - sa;
            M = m + b * 2;
        }
        else if (b > sb) {
            m = b - sb;
            M = m + a * 2;
        }
        else {
            m = 0;
            M = m + min(a, b) * 2;
        }
        for (int i = m; i <= M; i += 2) ans[i] = true;
        };
    int x = (n + 1) / 2, y = n / 2;
    go(x, y); go(y, x);
    cout << count(ans.begin(), ans.end(), true) << endl;
    for (int i = 0; i <= n; i++) {
        if (ans[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
