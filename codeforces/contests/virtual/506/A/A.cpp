#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string t;
    cin >> n >> k >> t;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (t.substr(0, i) == t.substr(n - i, i)) cnt = i;
    }
    string ans;
    for (int i = 0; i < k; i++) {
        ans += (i ? t.substr(cnt, n - cnt) : t);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}