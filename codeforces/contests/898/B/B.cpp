#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    int mandatory = 0, optional = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i]) optional++;
        else mandatory++;
    }
    vector<int> ans(n + 1);
    for (int j = 0; j <= optional; j++) {
        int i = mandatory + 2 * j;
        ans[i] = 1;
        if (n & 1 && i + 1 <= n) ans[i + 1] = 1;
    }
    for (auto& c : ans) cout << c;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}