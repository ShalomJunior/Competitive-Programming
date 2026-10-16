#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> s(n);
    for (auto& [x, y] : s) cin >> x >> y;
    unordered_map<int, int> want;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        want[x] = y;
    }
    int ans = INF;
    unordered_set<int> gan;
    set<int> idx;
    unordered_map<int, int> have;
    unordered_map<int, deque<pair<int, int>>> in;
    for (int i = 0; i < n; i++) {
        auto [x, y] = s[i];
        if (want.find(x) == want.end()) continue;
        have[x] += y;
        in[x].push_back({ y, i });
        idx.insert(i);
        while (have[x] - in[x][0].first >= want[x]) {
            have[x] -= in[x][0].first;
            idx.erase(in[x][0].second);
            in[x].pop_front();
        }
        if (have[x] >= want[x])  gan.insert(x);
        if ((int)gan.size() == m) {
            ans = min(ans, *idx.rbegin() - *idx.begin() + 1);
        }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}