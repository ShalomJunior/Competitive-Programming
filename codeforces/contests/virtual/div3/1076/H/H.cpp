#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6;
const int INF = 1e18;
vector<int> H(N);

uint64_t rng() {
    static mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> distribution(0, numeric_limits<uint64_t>::max());
    return distribution(generator);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x[i] = x[i - 1] ^ H[a[i]];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (x[r] ^ x[l - 1] ? "NO" : "YES") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < N; i++) H[i] = rng() % INF;
    int t; cin >> t;
    while (t--)solve();
}


