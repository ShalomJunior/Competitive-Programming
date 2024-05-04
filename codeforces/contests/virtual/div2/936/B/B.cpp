#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
const int MOD = 1e9 + 7;
int modPow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int g(vector<int> a) {
    int n = a.size();
    int best = -INF;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
    }
    return best;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int s = accumulate(a.begin(), a.end(), 0LL);
    int mx = max(g(a), 0LL);
    int ans = (s - mx) % MOD;
    ans += modPow(2, k, MOD) * (mx % MOD);
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}