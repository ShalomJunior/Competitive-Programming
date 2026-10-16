#include <bits/stdc++.h>
#define int long long
using namespace std;

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    int h = 0;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (primes[j] <= a[i]) {
            h += a[i] - primes[i];
            j++;
        }
        else if (a[i] + h >= primes[i]) {
            h -= primes[i] - a[i];
            j++;
        }
        else {
            ans++;
        }
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
