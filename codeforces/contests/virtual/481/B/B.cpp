#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') cnt++;
        if (s[i] != 'x') {
            if (cnt >= 3) ans += cnt - 2;
            cnt = 0;
        }
        if (i == n - 1 && cnt >= 3) ans += cnt - 2;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}