#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    for (int k = 2; k <= n; k++) {
        int m = 2 * k - 2;
        int r = n % m;
        int res;
        if (r == 0) {
            res = 2;
        }
        else {
            res = (r <= k ? r : k - (r - k));
        }
        if (res == x) cout << k << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}