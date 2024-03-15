#include<bits/stdc++.h>
using namespace std;

const int M = 25;
const int N = 2e6;
vector<int> p(N);
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

void solve() {
    int h; cin >> h;
    int ans = -1;
    for (int i = 0; i < M && h >= p[i]; i++) {
        int r = h - p[i];
        if (r == 0) {
            if (ans == -1) ans = i + 1;
            else ans = min(ans, i + 1);
        }
        auto it = lower_bound(primes.begin(), primes.end(), r);
        if (*it == r) {
            ans = i + 2;
            break;
        }
    }
    if (prime[h]) ans = 1;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    p[0] = 1;
    for (int i = 1; i < M; i++) p[i] = p[i - 1] + (1 << i);
    int t; cin >> t;
    while (t--)solve();
}