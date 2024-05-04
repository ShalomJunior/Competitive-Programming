#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    if (n < k || x < k - 1) {
        cout << -1 << endl;
        return;
    }
    int M = max(k - 1, x);
    cout << k * (k - 1) / 2 + (n - k) * (x == k ? x - 1 : x) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}