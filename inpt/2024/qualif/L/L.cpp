#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
bitset<N> prime;
vector<int> primes;
unordered_set<int> s;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i) prime.reset(j);
    }
    for (auto& c : primes) s.insert(c);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    for (auto& c : primes) {
        if (c > n / 2) break;
        if (s.count(n - c)) ans.push_back({ c, n - c });
    }
    cout << ans.size() << endl;
    for (auto& [l, r] : ans) cout << l << " " << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--) solve();
}