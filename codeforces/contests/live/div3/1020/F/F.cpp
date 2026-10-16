#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int top = (s[0] == '0' ? 0 : 1);
    int bot = (s[0] == '0' ? n - 1 : 0);
    for (int j = 1; j < n; j++) {
        if (s[j] == '0') {
            if (s[j - 1] == '0') {

            }
            else {
                bot += j;
            }
            top += j;
            bot += (n - j - 1);
        }
        else {
            if (s[j - 1] == '0') {
                top = 0;
                bot++;
            }
            else {
                top = 0;
                bot = 1;
            }
        }
        ans = max({ ans, top, bot });
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
