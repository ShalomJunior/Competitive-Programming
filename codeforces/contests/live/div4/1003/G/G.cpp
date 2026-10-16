#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
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

auto dec(int n) {
    vector<pair<int, int>> D;
    int i = 0;
    while (n > 1 && i < (int)primes.size()) {
        if (prime[n]) {
            D.push_back({ n, 1 });
            return D;
        }
        int cnt = 0;
        while (n % primes[i] == 0) {
            cnt++;
            n /= primes[i];
        }
        if (cnt) D.push_back({ primes[i], cnt });
        i++;
    }
    if (n > 1) D.push_back({ n, 1 });
    return D;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    long long ans = 0;
    vector<int> h(n + 1);
    vector<int> cnt(n + 1);
    int sng = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        auto D = dec(x);
        int m = D.size();
        int mx = 0;
        for (auto& [p, b] : D) mx = max(mx, b);
        if (m == 1) {
            if (D[0].second == 1) {
                cnt[x]++;
                sng++;
                ans += sng - cnt[x];
                if (1LL * x * x <= n) ans += cnt[x * x];
                ans += h[x];
            }
            else if (D[0].second == 2) {
                cnt[x]++;
                ans += cnt[D[0].first];
                ans += cnt[x];
            }
            else {}
        }
        else if (m == 2) {
            if (max(D[0].second, D[1].second) == 1) {
                cnt[x]++;
                ans += cnt[D[0].first];
                ans += cnt[D[1].first];
                ans += cnt[x];
                h[D[0].first]++;
                h[D[1].first]++;
            }
        }
        else {}
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}
