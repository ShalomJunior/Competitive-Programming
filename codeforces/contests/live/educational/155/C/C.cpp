#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<int> a = { 1 };
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) a.back()++;
        else a.push_back(1);
    }
    int m = a.size();
    long long ways = 1;
    for (int i = 0; i < m; i++) {
        ways *= a[i];
        ways %= MOD;
    }
    for (int i = 1; i <= n - m; i++)
        ways = (ways * i) % MOD;
    cout << n - m << " " << ways << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
