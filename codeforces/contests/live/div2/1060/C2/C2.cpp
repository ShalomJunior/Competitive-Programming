#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;
const int INF = 1e18;
bitset<N> prime;
vector<int> primes;
vector<vector<int>> divs(N + 1);

void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++) prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i) prime.reset(j);
    }
}

vector<int> g(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> all;
    map<int, int> h;
    for (auto& c : a) {
        cin >> c;
        if (divs[c].empty()) {
            divs[c] = g(c);
        }
        for (auto& x : divs[c]) {
            if (prime[x]) all.insert(x);
            h[x]++;
        }
    }
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    for (auto& [k, v] : h) {
        if (k != 1 && v > 1) {
            cout << 0 << endl;
            return;
        }
    }
    int X = INF;
    map<int, vector<int>> can;
    for (int i = 0; i < n; i++) {
        int u = a[i] + 1;
        if (divs[u].empty()) {
            divs[u] = g(u);
        }
        for (auto& x : divs[u]) {
            can[x].push_back(b[i]);
            sort(can[x].begin(), can[x].end());
            if (can[x].size() > 2) can[x].pop_back();
            if (x != 1 && h.find(x) != h.end()) {
                X = min(X, b[i]);
            }
        }
    }
    int Y = INF;
    for (auto& [k, v] : can) {
        if (k != 1 && v.size() == 2) {
            Y = min(Y, v[0] + v[1]);
        }
    }
    int Z = INF;
    int mn = *min_element(b.begin(), b.end());
    int cnt = count(b.begin(), b.end(), mn);
    if (cnt == 1) {
        int j = 0;
        while (b[j] != mn) j++;
        for (auto& x : divs[a[j]]) {
            if (prime[x]) all.erase(all.find(x));
        }
        all.erase(1);
        for (auto& x : all) {
            int r = a[j] % x;
            if (r == 0) {
                Z = min(Z, 0LL);
            }
            else {
                Z = min({ Z, b[j] * (x - r) });
            }
        }
    }
    else {
        Z = mn * 2;
    }
    cout << min({ X, Y, Z }) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    prepare();
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
