#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int m = s.size();
    int ans = 100;
    for (int i = m - 1; i >= 0; i--) {
        if (s[i] == '0') {
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == '0' || s[j] == '5') {
                    ans = min(ans, m - j - 2);
                    break;
                }
            }
        }
        if (s[i] == '5') {
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == '2' || s[j] == '7') {
                    ans = min(ans, m - j - 2);
                    break;
                }
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