#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    string s, t;
    cin >> s >> t;
    x %= n;
    if (x > 0) s = s.substr(n - x, x) + s;
    int mis = 0;
    for (int i = 0; i < n; i++) {
        mis += s[i] != t[i];
    }
    cout << mis << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}