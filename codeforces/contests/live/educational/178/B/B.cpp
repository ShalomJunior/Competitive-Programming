#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> mx(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx[i] = max(mx[i - 1], a[i]);
    }
    int s = 0;
    int mn = INF;
    for (int i = 0; i < n; i++) {
        s += a[n - i];
        mn = min(mn, a[n - i]);
        if (a[n - i] < mx[n - i - 1]) {
            cout << s - a[n - i] + mx[n - i - 1];
        }
        else {
            cout << s;
        }
        cout << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
