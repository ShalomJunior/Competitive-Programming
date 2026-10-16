#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a') {
            ans = (ans + cnt) % MOD;
            cnt = (cnt * 2) % MOD;
        }
        else {
            cnt++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
