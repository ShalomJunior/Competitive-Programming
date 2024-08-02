#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
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

        if (n == r || r == 0)
            return 1;

        T result = (factorial[n] * invFactorial[r]) % mod;
        result = (result * invFactorial[n - r]) % mod;

        return result;
    }
};

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int all = count(s.begin(), s.end(), '1');
    Combinatorics comb(n, MOD);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        for (int j = i; j < n; j++) {
            x += s[j] == '0';
            y += s[j] == '1';
            if (all < k || y > k) continue;
            int a = x;
            int b = y;
            s[i] == '0' ? b-- : a--;
            s[j] == '0' ? b-- : a--;
            if (a < 0 || b < 0) continue;
            ans += comb.nCr(a + b, a);
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
