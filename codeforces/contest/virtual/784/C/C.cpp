#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    bool b0 = true, b1 = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 1) {
            (i & 1) ? b1 &= ((a[1] & 1) == (a[i] & 1)) : b0 &= ((a[0] & 1) == (a[i] & 1));
        }
    }
    cout << ((b0 & b1) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}