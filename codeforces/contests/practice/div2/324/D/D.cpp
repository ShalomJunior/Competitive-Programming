#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6;
const int M = 100;
bitset<N> prime;
vector<int> primes;
vector<bool> can(M + 1);

template<typename T>
T power(T base, T exp, T mod) {
    T res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res;
}

template<typename T>
class MillerRabin {
private:
    std::vector<T> bases;

    bool check(T n, T a) {
        if (a >= n) return true;

        T m = n - 1;
        int k = 0;
        while (m % 2 == 0) {
            m /= 2;
            k++;
        }

        T x = power(a, m, n);
        if (x == 1 || x == n - 1) return true;

        for (int i = 0; i < k - 1; ++i) {
            x = (__int128)x * x % n;
            if (x == n - 1) return true;
        }

        return false;
    }

public:
    MillerRabin() {
        bases = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
    }

    bool isPrime(T n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (T base : bases) {
            if (!check(n, base)) {
                return false;
            }
        }
        return true;
    }
};

void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i) prime.reset(j);
    }
}

void init() {
    prepare();
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (prime[i] && prime[j]) {
                can[i] = 1;
                can[j] = 1;
                can[i + j] = 1;
            }
        }
    }
}

void get(int sum, vector<int>& a) {
    if (prime[sum]) {
        a.push_back(sum);
        return;
    }
    for (int i = 2; i < N; i++) {
        for (int j = 2; j < N; j++) {
            if (prime[i] && prime[j] && i + j == sum) {
                a.push_back(i);
                a.push_back(j);
                return;
            }
        }
    }
    assert(false);
}

void solve() {
    int n;
    cin >> n;
    MillerRabin<int> mr;
    if (mr.isPrime(n)) {
        cout << 1 << "\n";
        cout << n << endl;
        return;
    }
    bool f = false;
    vector<int> ans;
    for (int j = 2; j <= N; j++) {
        if (can[j] && mr.isPrime(n - j)) {
            ans.push_back(n - j);
            get(j, ans);
            f = true;
            break;
        }
    }
    assert(f);
    cout << ans.size() << "\n";
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    solve();
}
