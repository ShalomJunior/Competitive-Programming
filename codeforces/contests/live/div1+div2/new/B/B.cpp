#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += s[i] - '0';
        if (i >= m) cnt -= s[i - m] - '0';
        if (i >= m - 1) {
            if (cnt == 0) {
                for (int j = 0; j < k && i + j < n; j++) s[i + j] = '1';
                ans++;
                cnt++;
            }
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
