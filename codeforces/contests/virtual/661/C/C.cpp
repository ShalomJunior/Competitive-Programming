#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        w[c]++;
    }
    int ans = 0;
    for (int i = 2; i <= 2 * n; i++) {
        int t = 0;
        for (int j = 1; j < i - j; j++) {
            if (i - j <= n) t += min(w[j], w[i - j]);
        }
        if (i % 2 == 0) t += w[i / 2] / 2;
        ans = max(ans, t);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}