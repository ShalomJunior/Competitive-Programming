#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int s = 0;
    int p = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        p *= x;
    }
    cout << s * p << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}