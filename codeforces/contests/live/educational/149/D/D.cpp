#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 5e18;
const int C = 1e12;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int o = 0;
    int z = count(s.begin(), s.end(), '0');
    int ans = z * (C + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            z--;
            bool b = (i && s[i - 1] == '1');
            int cost = (o + z) * (C + 1);
            if (b) cost--;
            ans = min(ans, cost);
        }
        else o++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}

