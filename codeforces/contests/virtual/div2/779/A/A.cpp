#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')p.push_back(i);
    }
    int m = p.size();
    int ans = 0;
    for (int i = 1; i < m; i++) {
        int in = p[i] - p[i - 1] - 1;
        if (in < 2)ans += 2 - in;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}