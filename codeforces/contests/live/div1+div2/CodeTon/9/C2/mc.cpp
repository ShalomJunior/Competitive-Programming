#include <bits/stdc++.h>
#define int long long
using namespace std;


const int N = 1e5;
uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

int brute(int x, int m) {
    int ans = 0;
    stringstream ss;
    for (int y = 1; y <= m; y++) {
        int v = x ^ y;
        if (v % x == 0 || v % y == 0) {
            ans++;
            //cerr << y << " -> ";
            ss << v / x << " ";
        }
    }
    //cerr << endl;
    //cerr << "ss " << ss.str() << endl;
    return ans;
}
void solve(int x, int m) {
    // int x, m;
    // cin >> x >> m;
    if (x == 1) {
        cout << m << endl;
        return;
    }
    int j = 1;
    while (j * 2 <= x) j *= 2;
    int ans = 0;
    for (int y = 1; y <= m && y < j * 2; y++) {
        int v = x ^ y;
        if (v % x == 0 || v % y == 0) {
            ans++;
        }
    }
    //cerr << endl;
    int q = 1;
    for (int i = 0; i <= N; i++) {
        int k = m - i;
        int X = x ^ k;
        if (X % x == 0) q = max(q, X / x);
    }
    int mine = ans + q - 1;
    for (int k = q - 1; k > 1 && k > q - 4; k--) {
        int X = k * x;
        int y = X ^ x;
        if (y > m) mine--;
    }
    int br = brute(x, m);
    if (mine != br) {
        cerr << x << " " << m << endl;
        cerr << mine << " " << br << " " << q << endl;
        assert(false);
    }

    //cout << ans + q - 1 << endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //while (t--) solve();
    const int M = 1e5;
    int x = rng() % M;
    int m = rng() % M;
    while (t--)solve(x, m);
}