#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (cnt == 0) ans++;
            cnt++;
        }
        if (i - k + 1 >= 0 && s[i - k + 1] == '1') cnt--;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
