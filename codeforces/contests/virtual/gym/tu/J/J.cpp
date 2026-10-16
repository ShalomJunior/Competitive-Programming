#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 18;
const int MOD = 1e9 + 7;
vector<int> m(N);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<vector<int>> b;
    for (int i = 1; i < m[n]; i++) {
        vector<int> curr;
        for (int j = 0; j < n; j++) {
            if (i & m[j]) {
                curr.push_back(a[j]);
            }
        }
        b.push_back(curr);
    }
    sort(b.begin(), b.end());
    int q;
    cin >> q;
    vector<array<int, 3>> Q(q);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        --r;
        Q[i] = { l, r, x };
    }
    sort(Q.begin(), Q.end());
    map<int, int> in;
    multiset<pair<int, int>> end;
    for (int i = 0, j = 0; i < b.size(); i++) {
        while (j < q && Q[j][0] == i) {
            auto [l, r, x] = Q[j];
            in[x]++;
            end.insert({ r, x });
            j++;
        }
        int ans = 1;
        set<int> ps(b[i].begin(), b[i].end());
        for (auto& p : a) {
            if (ps.count(p)) {
                if (in[p] % 2 == 0) ans = ans * p % MOD;
            }
            else {
                if (in[p] & 1) ans = ans * p % MOD;
            }
        }
        cout << ans % MOD << " ";
        while (!end.empty() && end.begin()->first == i) {
            in[end.begin()->second]--;
            end.erase(end.begin());
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    m[0] = 1;
    for (int i = 1; i < N; i++) m[i] = m[i - 1] * 2;
    solve();
}
