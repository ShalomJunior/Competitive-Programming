#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int pass = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '0') pass++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i] == '0' && b[i] == '1') {
                ans++;
                if (pass) pass--;
            }
        }
    }
    cout << ans + pass << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
