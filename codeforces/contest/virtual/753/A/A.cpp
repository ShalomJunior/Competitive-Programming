#include <bits/stdc++.h>
using namespace std;

void solve() {
    string k, s; cin >> k >> s;
    map<char, int> h;
    for (int i = 0; i < k.length(); i++) h[k[i]] = i + 1;
    int ans = 0;
    for (int i = 1; i < s.length(); i++) {
        ans += abs(h[s[i]] - h[s[i - 1]]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}