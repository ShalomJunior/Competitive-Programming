#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; char c; string s;
    cin >> n >> c >> s;

    if (c == 'g') {
        cout << 0 << endl;
        return;
    }

    s += s;
    bool b = false;
    int curr = 0, ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == c && !b) {
            curr = i;
            b = true;
        }
        else if (s[i] == 'g' && b) {
            ans = max(ans, i - curr);
            b = false;
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}