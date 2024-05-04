#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(m), h(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i] >> h[i];
    }
    int ans = *max_element(h.begin(), h.end());
    for (int i = 1; i < m; i++) {
        int len = d[i] - d[i - 1] - 1;
        int delta = abs(h[i] - h[i - 1]);
        if (delta > len + 1) {
            cout << "IMPOSSIBLE " << endl;
            return;
        }
        int x = min(h[i], h[i - 1]);
        int y = max(h[i], h[i - 1]);
        for (int j = 0; j <= len; j++) {
            if (abs(y + j - (len - j) - x) <= 1)
                ans = max(ans, y + j);
        }
    }
    ans = max(ans, h[0] + d[0] - 1);
    ans = max(ans, h[m - 1] + n - d[m - 1]);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
