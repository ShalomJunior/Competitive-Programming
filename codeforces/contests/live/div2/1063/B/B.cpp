#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    string x;
    cin >> x;
    if (count(x.begin(), x.end(), '1') == 0) {
        cout << 0 << endl;
        return;
    }
    x = "#" + x;
    int a = 1;
    int b = 1;
    while (p[a] != 1) a++;
    while (p[b] != n) b++;
    if (x[a] == '1' || x[b] == '1') {
        cout << -1 << endl;
        return;
    }
    int f = 1;
    int l = n;
    while (x[f] == '0') f++;
    while (x[l] == '0') l--;
    int ans = 0;
    stringstream ss;
    if (f < b) {
        if (f == 1) {
            cout << -1 << endl;
            return;
        }
        int mn = n;
        for (int k = f; k <= b; k++) {
            if (x[k] == '1')
                mn = min(mn, p[k]);
        }
        int j = 1;
        for (int k = 1; k < f; k++) {
            if (p[k] < p[j]) j = k;
        }
        if (p[j] > mn) {
            cout << -1 << endl;
            return;
        }
        ans++;
        ss << j << " " << b << endl;
    }
    if (b < l) {
        if (l == n) {
            cout << -1 << endl;
            return;
        }
        int mn = n;
        for (int k = b; k <= l; k++) {
            if (x[k] == '1')
                mn = min(mn, p[k]);
        }
        int j = l + 1;
        for (int k = l + 1; k <= n; k++) {
            if (p[k] < p[j]) j = k;
        }
        if (p[j] > mn) {
            cout << -1 << endl;
            return;
        }
        ans++;
        ss << b << " " << j << endl;
    }
    cout << ans << endl;
    cout << ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
