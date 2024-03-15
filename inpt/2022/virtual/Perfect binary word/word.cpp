#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s.substr(i, 3) == "111") {
            ans++; i += 2;
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}