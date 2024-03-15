#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    if (n < 3) cout << 1;
    else {
        n -= 2;
        int ans = 1 + n / x;
        cout << (n % x ? ans + 1 : ans);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}