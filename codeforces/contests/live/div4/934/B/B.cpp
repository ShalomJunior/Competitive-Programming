#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        bool b = i & 1 ? false : true;
        string ans;
        for (int j = 0; j < n; j++) {
            ans += (b ? "##" : "..");
            b = !b;
        }
        cout << ans << endl;
        cout << ans << endl;
        b = !b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
