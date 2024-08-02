#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int mis = 0;
    for (int i = 0; i + 1 < n; i++) {
        mis += s[i] == s[i + 1];
    }
    cout << (mis + 1) / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
