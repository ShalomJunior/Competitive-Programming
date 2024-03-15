#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if (b == 0) {
        if (a) cout << string(a + 1, '0');
        else cout << string(c + 1, '1');
        cout << endl;
        return;
    }
    string ans;
    for (int i = 0; i < b + 1; i++)
        ans += ('0' + i % 2);
    ans = string(a, '0') + ans;
    if (b & 1) ans += string(c, '1');
    else {
        ans.pop_back();
        ans += string(c, '1');
        ans += '0';
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}