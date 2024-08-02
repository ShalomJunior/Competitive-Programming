#include <bits/stdc++.h>
#define int long long
using namespace std;

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

template<typename T>
class fenwick {
public:
    vector<T> arr;
    fenwick(int n) {
        arr.resize(n + 3);
    }
    void add(int index, T val) {
        for (; index < arr.size(); index += (index & (-index))) {
            arr[index] += val;
        }
    }
    T query(int index) {
        T sum = 0;
        for (; index > 0; index -= (index & (-index))) {
            sum += arr[index];
        }
        return sum;
    }
    T rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

const int MOD = 998244353;
const int N = 5000;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    Combinatorics comb(n, MOD);
    vector<int> dp(N);
    dp[0] = 1;
    fenwick<int> fen(N);
    for (int i = 1; i <= n; i++) {
        if (a[i] <= 0) continue;
        for (int j = i + a[i]; j <= n; j++) {
            int len = j - i - 1;
            int L = fen.rangeQuery(1, i - 1) + 1;
            int R = comb.nCr(len, a[i] - 1);
            int add = (L % MOD) * (R % MOD) % MOD;
            dp[j] += add;
            fen.add(j, add);
        }
    }
    cout << fen.rangeQuery(1, n) % MOD << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
