#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int N = 1e6 + 5;
const int INF = 1e9;
bitset<N> prime;
vector<int> primes;
void prepare() {
    primes.reserve(N);
    for (int i = 2; i < N; i++)prime.set(i);
    for (int i = 2; i < N; i++) {
        if (!prime[i])continue;
        primes.push_back(i);
        for (long long j = 1LL * i * i; j < N; j += i)prime.reset(j);
    }
}

int dec(int n) {
    int i = 0, ans = 1;
    while (n > 1 && i < primes.size()) {
        if (n < N && prime[n]) {
            return ans * n;
        }
        if (n % primes[i])i++;
        else {
            int cnt = 0;
            while (n % primes[i] == 0) {
                cnt++;
                n /= primes[i];
            }
            if (cnt & 1) ans *= primes[i];
            i++;
        }
    }
    if (n > 1) ans *= n;
    return ans;
}

void solve() {
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[dec(x)]++;
    }
    int x = 0, y = 0, z = 0, M = 0;
    for (auto& [k, v] : cnt) {
        if (k == 1) z = v;
        else {
            v & 1 ? y = max(y, v) : x += v;
        }
        M = max(M, v);
    }
    int q; cin >> q;
    while (q--) {
        long long w; cin >> w;
        cout << (w ? max(x + z, y) : M) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t; cin >> t;
    while (t--)solve();
}