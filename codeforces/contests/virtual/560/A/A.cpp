#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;  string s;
    cin >> n >> x >> y >> s;
    reverse(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < x; i++) {
        if (i == y) {
            if (s[i] == '0') ans++;
        }
        else if (s[i] == '1') ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}