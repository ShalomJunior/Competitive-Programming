#include <bits/stdc++.h>
using namespace std;

void dbg(vector<char>& a) {
    int n = a.size();
    int i = 0;
    while (i < n && a[i] == '0') i++;
    string ans;
    while (i < n) ans += a[i++];
    cout << (ans.empty() ? "0" : ans) << endl;
}

void solve() {
    string x, y;
    cin >> x >> y;
    int n = x.size();
    int m = y.size();
    int len = max(n, m);
    if (n < m) swap(x, y);
    vector<char> a(len, '0'), b(len, '0');
    for (int i = 0; i < n; i++) {
        a[len - 1 - i] = x[n - 1 - i];
    }
    for (int i = 0; i < m; i++) {
        b[len - 1 - i] = y[m - 1 - i];
    }
    int j = 0;
    while (j < len && a[j] == b[j]) j++;
    if (j < len) {
        if (a[j] < b[j]) swap(a[j], b[j]);
        j++;
    }
    while (j < len) {
        if (a[j] > b[j]) {
            swap(a[j], b[j]);
        }
        j++;
    }
    dbg(a);
    dbg(b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
