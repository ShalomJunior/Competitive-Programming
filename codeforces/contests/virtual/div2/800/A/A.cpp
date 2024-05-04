#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    string ans;
    while (a && b) {
        ans += "01";
        a--, b--;
    }
    while (a--) ans += '0';
    while (b--) ans += '1';
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}