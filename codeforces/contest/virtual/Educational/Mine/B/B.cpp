#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> s(n), e(n);
    for (auto& c : s) cin >> c;
    for (auto& c : e) cin >> c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == e[i]) continue;
        if (i + 1 == n) {
            cout << "impossible" << endl;
            return;
        }
        int x = 0;
        while ((s[i] + x) % 10 != e[i]) x++;
        int y = 0;
        while ((s[i] - y + 10) % 10 != e[i]) y++;
        if (x < y) s[i + 1] = (s[i + 1] + x) % 10;
        else s[i + 1] = (s[i + 1] - y + 10) % 10;
        ans += min(x, y);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
