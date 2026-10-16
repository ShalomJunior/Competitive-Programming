#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int cnt = count(s.begin(), s.end(), '1');
    for (int i = 0; i < n; i++) {
        ans += s[i] == '0' ? cnt + 1 : cnt - 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
