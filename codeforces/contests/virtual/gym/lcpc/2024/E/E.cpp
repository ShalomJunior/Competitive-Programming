#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

struct Query {
    int l, r, a;
    bool operator<(const Query& other) const {
        if (l != other.l) return l < other.l;
        return r < other.r;
    }
};

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, q, k;
    cin >> n >> q >> k;
    vector<Query> Q(q);
    for (int i = 0; i < q; i++) {
        int a, l, r;
        cin >> a >> l >> r;
        Q[i] = { l - 1, r - 1, a };
    }
    sort(Q.begin(), Q.end());
    set<pair<int, int>> in;
    int z = 0;
    for (int i = 0, j = 0; i < n; i++) {
        z = (z * k) % MOD;
        while (j < q && Q[j].l == i) {
            auto [l, r, a] = Q[j];
            in.insert({ r, a * power(k, r - l) % MOD });
            z = (z + Q[j].a) % MOD;
            j++;
        }
        cout << z << " ";
        while (!in.empty() && in.begin()->first == i) {
            z = z - in.begin()->second % MOD;
            z = (z + MOD) % MOD;
            in.erase(in.begin());
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}