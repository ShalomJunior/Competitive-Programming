#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        bool skip = false;
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '-') {
                x++;
                if (skip) {
                    cnt++;
                    skip = false;
                }
                else skip = true;
            }
            else {
                y++;
                skip = false;
            }
            int d = x - y;
            if (d >= 0 && d % 3 == 0) {
                if (d / 3 <= cnt) ans++;
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