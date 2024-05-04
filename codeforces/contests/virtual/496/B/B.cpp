#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    int cnt = 0;
    for (int i = 1; i <= min(n, m); i++) {
        if (s[n - i] == t[m - i]) cnt++;
        else break;
    }
    cout << n + m - 2 * cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}