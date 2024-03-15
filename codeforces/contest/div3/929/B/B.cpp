#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(3);
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        a[x % 3]++;
    }
    if (s % 3 == 0) {
        cout << 0 << endl;
        return;
    }
    if (a[s % 3] || s % 3 == 2) {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
