#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    long long ans = 0;
    for (auto& c : s) {
        if (c == '0') {
            if (cnt) ans += cnt + 1;
        }
        else cnt++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
