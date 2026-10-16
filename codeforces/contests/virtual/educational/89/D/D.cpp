#include <bits/stdc++.h>
#define int long long
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

auto dec(int n) {
    vector<pair<int, int>> D;
    int i = 0;
    while (n > 1 && i < (int)primes.size()) {
        if (prime[n] || primes[i] * primes[i] > n) {
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
    if (n > 1) D.push_back({ 1, n });
    return D;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> ans(N);
    pair<int, int> p = { 0, 0 };
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        if (ans[x] == p) {
            auto D = dec(x);
            int m = D.size();
            if (m > 1) {
                auto g = D.back();
                int z = pow(g.first, g.second);
                ans[x] = { z, x / z };
            }
            else {
                ans[x] = { -1, -1 };
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[a[i]].first << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[a[i]].second << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    solve();
}
