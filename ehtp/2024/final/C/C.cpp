#include<bits/stdc++.h>
using namespace std;

struct Group {
    int l;
    int r;
    int s;
    bool operator<(const Group& other) const {
        return l < other.l;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> all;
    vector<Group> G;
    for (int i = 0; i < n; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        G.push_back({ l, r, s });
        all.push_back(l);
        all.push_back(r);
    }
    multiset<int> S;
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        S.insert(s);
    }
    sort(G.begin(), G.end());
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int j = 0;
    int ans = 0;
    set<pair<int, int>> out;
    for (auto& c : all) {
        if (j < n && G[j].l == c) {
            auto it = S.lower_bound(G[j].s);
            if (it != S.end()) {
                out.insert({ G[j].r, *it });
                S.erase(it);
                ans++;
            }
            j++;
        }
        while (!out.empty() && out.begin()->first == c) {
            S.insert(out.begin()->second);
            out.erase(out.begin());
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}