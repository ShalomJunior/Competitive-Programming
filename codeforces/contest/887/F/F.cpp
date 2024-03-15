#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
void solve() {
    int n; cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int curr = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j)continue;
            curr += a[j];
            if (i / j != j && a[i / j]) curr += a[i / j];
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}