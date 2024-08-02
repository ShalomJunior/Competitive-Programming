#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e7;
const int INF = 1e8;
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

void dec(int n, vector<int>& res) {
    int i = 0;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            res.push_back(n);
            return;
        }
        int cnt = 0;
        while (n % primes[i] == 0) {
            cnt++;
            n /= primes[i];
        }
        if (cnt) res.push_back(primes[i]);
        i++;
    }
    if (n > 1) res.push_back(n);
}

void solve() {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    if (__gcd(x, y) != 1) {
        cout << 0 << endl;
        return;
    }
    if (x + 1 == y) {
        cout << -1 << endl;
        return;
    }
    int d = y - x;
    vector<int> p;
    dec(d, p);
    int mn = INF;
    for (auto& c : p) {
        int val = (x - x % c);
        if (x % c) val += c;
        mn = min(mn, val);
    }
    cout << mn - x << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}
