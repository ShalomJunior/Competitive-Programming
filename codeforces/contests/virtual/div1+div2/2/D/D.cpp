#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
const int N = 1e7;
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
    for (auto& c : primes) {
        if (n < N && prime[n]) {
            p.push_back(n);
            return p;
        }
        int cnt = 0;
        while (n % c == 0) {
            n /= c;
            cnt++;
        }
        if (cnt) p.push_back(c);
    }
    if (n > 1) p.push_back(n);
    return p;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    auto f = [&](vector<int>& p, int lim) {
        int k = p.size();
        int res = 0;
        for (int i = 1; i < (1 << k); i++) {
            int cnt = 0;
            int mult = 1;
            int sign = -1;
            for (int j = 0; j < k; j++) {
                if (i & (1 << j)) {
                    cnt++;
                    mult *= p[j];
                    sign *= -1;
                }
            }
            res += sign * lim / mult;
        }
        return lim - res;
        };
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] % a[i]) {
            cout << 0 << endl;
            return;
        }
        if (a[i - 1] == a[i]) {
            ans *= m / a[i];
        }
        else {
            auto p = dec(a[i - 1] / a[i]);
            int cnt = f(p, m / a[i]);
            ans *= cnt;
        }
        ans %= MOD;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}