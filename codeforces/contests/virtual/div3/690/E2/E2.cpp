#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
template <typename T>
class Combinatorics {
private:
    vector<T> factorial;
    vector<T> invFactorial;
    T mod;
public:
    Combinatorics(int maxSize, T modValue) : mod(modValue) {
        factorial.resize(maxSize + 1);
        invFactorial.resize(maxSize + 1);
        factorial[0] = invFactorial[0] = 1;
        for (int i = 1; i <= maxSize; ++i) {
            factorial[i] = (factorial[i - 1] * i) % mod;
            invFactorial[i] = modInverse(factorial[i], mod);
        }
    }
    T modInverse(T a, T m) {
        T m0 = m;
        T y = 0, x = 1;
        while (a > 1) {
            T q = a / m;
            T t = m;
            m = a % m;
            a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0)
            x += m0;
        return x;
    }
    T nCr(T n, T r) {
        assert(n >= r && r >= 0);
        if (n == r || r == 0) return 1;
        T result = (factorial[n] * invFactorial[r]) % mod;
        result = (result * invFactorial[n - r]) % mod;
        return result;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    Combinatorics comb(n, MOD);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = pre[i - 1] - pre[max(i - k - 1, 0LL)];
        for (int j = 1; j <= min(a[i], m);j++) {
            if (cnt < m - j) continue;
            int x = comb.nCr(cnt, m - j);
            int y = comb.nCr(a[i], j);
            ans += x * y % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}