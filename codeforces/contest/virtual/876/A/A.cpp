#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) { cout << n << endl; return; }
    else {
        int ans = n / k, rem = n % k;
        if (rem)ans++;
        if (rem != 1)ans++;
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}