#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    int mx = 0;
    for (int i = 0; i < m; i++) {
        int k = i;
        int cnt = 0;
        for (int j = 0; j < n && k < m; j++) {
            if (a[j] == b[k]) {
                k++;
                cnt++;
            }
        }
        mx = max(mx, cnt);
    }
    cout << n + m - mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
