#include <bits/stdc++.h>
using namespace std;

const int K = 25;
const int N = 1e7 + 5;
vector<int> power(K, 1);
vector<int> D(2 * N, -1);

bitset<N> prime;
vector<int> primes;
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
    for (int i = 1; i < K; i++) power[i] = power[i - 1] * 2;
    D[1] = 0;
    for (int i = 2; i < 2 * N; i++) {
        if (D[i] == -1)
            D[i] = 1;
        for (auto& p : primes) {
            if (i * p >= 2 * N) break;
            D[i * p] = D[i];
            if (i % p) D[i * p]++;
        }
    }
}

void solve() {
    int c, d, x;
    cin >> c >> d >> x;
    long long ans = 0;
    auto work = [&](int g) {
        int m = x / g + d;
        if (m % c) return;
        m /= c;
        ans += power[D[m]];
        };
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            work(i);
            if (i != x / i) work(x / i);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while (t--) solve();
}



/*

*/