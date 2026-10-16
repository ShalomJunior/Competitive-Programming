#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
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
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            for (int j = i; j <= n; j += i) {
                cnt[j]++;
            }
        }
    }
    cout << accumulate(cnt.begin(), cnt.end(), 0LL) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
