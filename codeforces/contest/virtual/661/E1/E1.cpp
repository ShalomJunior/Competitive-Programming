#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

struct Info {
    long long delta, to, w, m;
    bool operator<(const Info& other) const {
        return delta < other.delta;
    }
};

void solve() {
    int n; long long s;
    cin >> n >> s;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges(n - 1);
    map<pair<int, int>, int> w;
    for (int i = 0; i < n - 1; i++) {
        int a, b, p; cin >> a >> b >> p;
        --a, --b;
        if (a > b) swap(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        w[{a, b}] = p;
        edges[i] = { a, b };
    }
    vector<bool> vis(n);
    vector<int> leaves(n);
    function<int(int)> dfs = [&](int r) {
        vis[r] = true;
        int cnt = 0;
        for (auto& c : adj[r]) {
            if (!vis[c]) cnt += dfs(c);
        }
        leaves[r] = max(cnt, 1);
        return leaves[r];
        };
    dfs(0);
    long long sum = 0;
    multiset<Info> st;
    for (int i = 0; i < n - 1; i++) {
        auto p = edges[i];
        long long m = min(leaves[p.F], leaves[p.S]);
        sum += m * w[p];
        long long delta = m * w[p] - m * (w[p] / 2);
        st.insert(Info{ delta , m * (w[p] / 2), w[p] / 2, m });
    }
    int ans = 0;
    while (sum > s) {
        auto p = *prev(st.end());
        sum -= p.delta;
        st.erase(prev(st.end()));
        if (p.to - p.m * (p.w / 2) > 0) {
            st.insert(Info{ p.to - p.m * (p.w / 2), p.m * (p.w / 2), p.w / 2, p.m });
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}