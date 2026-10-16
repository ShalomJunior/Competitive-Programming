#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
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

void dec(int n, map<int, int>& div) {
    int i = 0;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            div[n]++;
            return;
        }
        while (n % primes[i] == 0) {
            div[primes[i]]++;
            n /= primes[i];
        }
        i++;
    }
    if (n > 1) div[n]++;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (is_sorted(a.begin(), a.end())) {
        cout << "Bob\n";
        return;
    }
    int mx = -1;
    for (int i = 0; i < n; i++) {
        map<int, int> mp;
        dec(a[i], mp);
        if (mp.begin()->first < mx) {
            cout << "Alice\n";
            return;
        }
        mx = max(mx, mp.rbegin()->first);
    }
    cout << "Bob\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}