#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edges {
    int a, b, w;
    bool operator<(const Edges& other) const {
        return w < other.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<Edges> specials(m);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        --x, --y;
        specials[i] = { x, y, w };
    }
    sort(specials.begin(), specials.end());
    int root = min_element(a.begin(), a.end()) - a.begin();
    vector<int> parents(n, root);
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        if (i != root) {
            cost[i] = a[i] + a[parents[i]];
        }
    }
    for (int i = 0; i < m; i++) {
        auto [x, y, w] = specials[i];
        if (cost[x] > cost[y]) swap(x, y);
        if (cost[y] > w) {
            cost[y] = w;
            parents[y] = x;
        }
    }
    int ans = accumulate(cost.begin(), cost.end(), 0LL);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}