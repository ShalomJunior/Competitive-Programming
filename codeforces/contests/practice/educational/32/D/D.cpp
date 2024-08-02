#include <bits/stdc++.h>
#define int long long
using namespace std;

int nCr(int n, int r) {
    assert(n >= r && r >= 0);
    if (n == r || r == 0) return 1;
    int num = 1;
    for (int i = n - r + 1; i <= n; i++) num *= i;
    int den = 1;
    for (int i = 1; i <= r; i++) den *= i;
    return num / den;
}

int get(int n) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int ans = 0;
    do {
        bool flag = true;
        for (int i = 0; i < n; i++) flag &= p[i] != i;
        if (flag) ans++;
    } while (next_permutation(p.begin(), p.end()));
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        ans += nCr(n, i) * get(i);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}