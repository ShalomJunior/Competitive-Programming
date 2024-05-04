#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0, j = -1;;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) {
            if (j != -1) ans += i - j - 1;
            j = i;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}