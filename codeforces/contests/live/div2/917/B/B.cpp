#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    long long ans = 0;
    set<char> let;
    for (int i = 0; i < n; i++) {
        let.insert(s[i]);
        ans += let.size();
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
