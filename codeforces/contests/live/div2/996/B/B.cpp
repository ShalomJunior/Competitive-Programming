#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    vector<int> b(n);
    int mn = INF;
    int need = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] >= b[i]) {
            mn = min(mn, a[i] - b[i]);
        }
        else {
            need = b[i] - a[i];
            cnt++;
        }
    }
    cout << (cnt > 1 || mn < need ? "NO" : "YES") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
