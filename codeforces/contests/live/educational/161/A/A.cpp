#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] != c[i]) {
                flag = true;
            }
        }
        else {
            if (c[i] != a[i] && c[i] != b[i]) {
                flag = true;
            }
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
