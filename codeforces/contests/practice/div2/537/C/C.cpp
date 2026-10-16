#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<int> x(k);
    for (auto& c : x) cin >> c;
    sort(x.begin(), x.end());
    auto cnt = [&](int l, int r) {
        auto it1 = lower_bound(x.begin(), x.end(), l);
        auto it2 = upper_bound(x.begin(), x.end(), r);
        return it2 - it1;
        };
    map<pair<int, int>, int> h;
    function<int(int, int)> go = [&](int l, int r) {
        if (h.count({ l, r })) return h[{l, r}];
        int in = cnt(l, r);
        if (in == 0) return h[{l, r}] = a;
        int len = r - l + 1;
        int mid = (l + r) / 2;
        int f = (l == r ? INF : go(l, mid) + go(mid + 1, r));
        int s = b * in * len;
        return h[{l, r}] = min(f, s);
        };
    cout << go(1, 1 << n) << endl;;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
