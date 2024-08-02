#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    int j = n - 1;
    k -= n;
    while (k > 0) {
        k -= j;
        ans++;
        if (k <= 0) break;
        k -= j;
        ans++;
        j--;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
