#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int open = 0, close = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') open++;
        else open ? open-- : ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}