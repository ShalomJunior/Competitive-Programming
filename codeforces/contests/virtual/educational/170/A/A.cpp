#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    int i = 0;
    int j = 0;
    while (i < n && j < m && a[i] == b[j]) i++, j++;
    cout << (i ? n + m - i + 1 : n + m) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
