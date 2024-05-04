#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        x ^= i;
        y ^= a[i];
    }
    if (n & 1) {
        cout << (x ^ y) << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if ((y ^ a[i]) == (x ^ a[i]))
    }
    cout << a[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}