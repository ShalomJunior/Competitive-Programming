#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = 4500;
const long long INF = 1e12;
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
    int n;
    long long pow;
    cin >> n >> pow;
    vector<int> h(n);
    for (auto& c : h) cin >> c;
    sort(h.begin(), h.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (pow >= h[i]) {
            cnt++;
            for (auto& p : primes) {
                if (p > M) {
                    pow += h[i];
                    break;
                }
                if (h[i] % p == 0) {
                    pow += p;
                    break;
                }
            }
        }
        else break;
    }
    cout << cnt << " " << pow << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}