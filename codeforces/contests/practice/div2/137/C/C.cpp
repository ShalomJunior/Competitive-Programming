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

vector<int> dec(int n) {
    vector<int> ans;
    for (auto& p : primes) {
        if (n < N && prime[n]) {
            ans.push_back(n);
            return ans;
        }
        if (n % p == 0) ans.push_back(p);
        while (n % p == 0) n /= p;
    }
    if (n > 1) ans.push_back(n);
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, vector<int>> f;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (auto& p : dec(a[i])) f[p].push_back(i);
    }
    vector<int> b(m);
    map<int, vector<int>> g;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        for (auto& p : dec(b[i])) g[p].push_back(i);
    }
    for (auto& p : primes) {
        while (!f[p].empty() && !g[p].empty()) {
            int i = f[p].back();
            int j = g[p].back();
            while (a[i] % p == 0 && b[j] % p == 0) {
                a[i] /= p;
                b[j] /= p;
            }
            if (a[i] % p) f[p].pop_back();
            if (b[j] % p) g[p].pop_back();
        }
    }
    cout << n << " " << m << endl;
    for (auto& c : a) cout << c << " ";
    cout << endl;
    for (auto& c : b) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    solve();
}
