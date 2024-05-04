#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (i + 1 < n) {
                if (a[i + 1] == b[i + 1] && a[i] != a[i + 1]) {
                    ans += 2;
                    i++;
                }
                else {
                    if (a[i] == '0') ans++;
                }
            }
            else {
                if (a[i] == '0') ans++;
            }
        }
        else ans += 2;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}