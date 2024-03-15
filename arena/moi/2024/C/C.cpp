#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = 1e6;
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

int dec(int n) {
    int i = 0, ans = 1;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            ans *= 2;
            return ans;
        }
        int cnt = 0;
        while (n % primes[i] == 0) {
            cnt++;
            n /= primes[i];
        }
        if (cnt) ans *= (1 + cnt);
        i++;
    }
    if (n > 1) ans *= 2;
    return ans;
}

vector<int> ans(M + 5);
void solve() {
    int n; cin >> n;
    if (!ans[n]) ans[n] = dec(n);
    cout << ans[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}