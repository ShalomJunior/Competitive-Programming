#include <bits/stdc++.h>
using namespace std;

bool is(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

void solve() {
    string s; cin >> s;
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (!is(s.substr(i, j)))ans = max(ans, j);
        }
    }
    cout << ((ans) ? ans : -1) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}