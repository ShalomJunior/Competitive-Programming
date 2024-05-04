#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> s(n), f(n);
    for (auto& c : s)cin >> c;
    for (auto& c : f)cin >> c;
    for (int i = 0; i < n; i++) {
        if (!i) { cout << f[i] - s[i] << " "; }
        else { cout << f[i] - max(f[i - 1], s[i]) << " "; }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}