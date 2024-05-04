#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 17;
int ans, fact[N];

void go(int n, int i, int chosen) {
    ans = min(ans, chosen + __builtin_popcountll(n));
    if (i < 0 || !n) return;
    if (n >= fact[i]) go(n - fact[i], i - 1, chosen + 1);
    go(n, i - 1, chosen);
}

void solve() {
    int n; cin >> n;
    ans = 1e18; go(n, 15, 0);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;
    int t; cin >> t;
    while (t--)solve();
}