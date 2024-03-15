#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
const int INF = 1e9;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++)prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i])continue;
        primes.push_back(i);
        for (int j = 1LL * i * i; j < N; j += i)prime.reset(j);
    }
}

void solve() {
    int d; cin >> d;
    int x = *lower_bound(primes.begin(), primes.end(), 1 + d);
    int y = *lower_bound(primes.begin(), primes.end(), x + d);
    cout << x * y << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}