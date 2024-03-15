#include <bits/stdc++.h>
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

void solve() {
    int n; cin >> n;
    for (int i = 0; i < N; i++) {
        if ((n - 1 - primes[i]) % primes[i]) {
            cout << primes[i] << " " << n - 1 - primes[i] << " ";
            break;
        }
    }
    cout << 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
