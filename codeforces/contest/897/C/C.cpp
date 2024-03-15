#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto& c : a) {
        cin >> c;
        if (c > 0) sum += c;
    }
    if (n == 1) {
        cout << max(a[0], 0LL) << endl;
        return;
    }
    else if (a[0] >= 0 || a[1] < 0) {
        cout << sum << endl;
        return;
    }
    int x = a[0] + sum, y = sum - a[1];
    cout << max({ x, y, 0LL }) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}