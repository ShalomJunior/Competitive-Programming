#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; long long y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int bit = x & 1;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) bit ^= 1;
    }
    cout << ((bit == (y & 1)) ? "Alice" : "Bob") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}