#include <bits/stdc++.h>
using namespace std;

auto work(vector<int> p, vector<int>& s) {
    int n = p.size();
    int root = -1;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) {
            adj[p[i]].push_back(i);
        }
        else {
            root = i;
        }
    }
    string ord;
    function<int(int r)> dfs = [&](int r) {
        ord += to_string(r + 1) + ' ';
        int ans = s[r];
        if (!adj[r].empty()) {
            int curr = 1;
            for (auto c : adj[r]) {
                assert(adj[r].size() <= 2);
                curr *= dfs(c);
            }
            ans += curr;
        }
        return ans;
        };
    int val = dfs(root);
    return make_pair(ord, val);
}

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (auto& c : s) cin >> c;
    int ans = 0;
    string order;
    function<void(int, vector<int>, int)> go = [&](int r, vector<int> p, int last) {
        if (r == n - 1) {
            auto [ord, val] = work(p, s);
            if (val > ans) {
                ans = val;
                order = ord;
            }
        }
        else {
            auto p1 = p;
            p1[r + 1] = r;
            go(r + 1, p1, last);
            auto p2 = p;
            p2[last] = r + 1;
            go(r + 1, p2, r + 1);
        }
        };
    vector<int> p(n, -1);
    go(0, p, 0);
    cout << ans << endl;
    cout << order << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
