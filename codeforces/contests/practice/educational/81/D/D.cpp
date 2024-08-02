#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
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

vector<int> dec(int n) {
    vector<int> p;
    for (int i = 0; i < (int)primes.size(); i++) {
        if (n < N && prime[n]) break;
        int cnt = 0;
        while (n % primes[i] == 0) {
            cnt++;
            n /= primes[i];
        }
        if (cnt) p.push_back(primes[i]);
    }
    if (n > 1) p.push_back(n);
    return p;
}

void solve() {
    int a, m;
    cin >> a >> m;
    int g = __gcd(a, m);
    int have = m - 1;
    int r = a % g;
    if (r > 0) r = g - r;
    have -= r;
    if (have < 0) {
        cout << 0 << endl;
        return;
    }
    int left = a + r;
    int right = left + (have / g) * g;
    left /= g;
    right /= g;
    auto p = dec(m / g);
    int k = p.size();
    int tot = right - left + 1;
    if (k == 0) {
        cout << tot << endl;
        return;
    }
    int mis = 0;
    for (int i = 1; i < (1 << k); i++) {
        int q = 0;
        int lc = 1;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                lc = lcm(lc, p[j]);
                q++;
            }
        }
        int cnt = right / lc - left / lc;
        if (left % lc == 0) cnt++;
        mis += (q & 1 ? 1 : -1) * cnt;
    }
    cout << tot - mis << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}
