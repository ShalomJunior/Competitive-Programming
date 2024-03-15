#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

int binp(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) { ans = (ans * a) % MOD; }
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

int inv(int a, int mod) { return binp(a, mod - 2); }

int fact(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    int ans = fact(n / 3);
    int den = inv(fact(n / 6), MOD);
    den = (den * den) % MOD;
    ans = (ans * den) % MOD;

    multiset<int> s;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        s.insert(a);
        if (i % 3 == 0) {
            ans = (ans * s.count(*s.begin())) % MOD;
            s.clear();
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}