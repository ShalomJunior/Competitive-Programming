#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 2e9;
void solve() {
    int n;
    cin >> n;
    int k = 1;
    while (n % k == 0) k *= 2;
    if (k <= INF && n >= k * (k + 1) / 2) {
        cout << k << endl;
        return;
    }
    k = 2 * n / k;
    cout << (k > 1 ? k : -1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
