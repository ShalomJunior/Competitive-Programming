#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> o(n + 1), z(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            z[i] = 1 + z[i + 1];
            o[i] = 0;
        }
        else {
            o[i] = 1 + o[i + 1];
            z[i] = 0;
        }
    }
    int x = *max_element(o.begin(), o.end());
    int y = *max_element(z.begin(), z.end());
    int k = max(x, y);
    int cnt = count(s.begin(), s.end(), '0');
    int ans = k * k;
    if (cnt && cnt < n) {
        ans = max(ans, cnt * (n - cnt));
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}