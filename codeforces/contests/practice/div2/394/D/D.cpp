#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), p(n);
    for (auto& c : a) cin >> c;
    for (auto& c : p) cin >> c;
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int& i, const int& j) {
        return p[i] > p[j];
        });
    int d = INF;
    vector<int> b(n);
    for (auto& j : o) {
        int lim = d - 1 + a[j];
        if (lim < l) {
            cout << -1 << endl;
            return;
        }
        b[j] = lim <= r ? lim : r;
        d = b[j] - a[j];
    }
    for (auto& c : b) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
