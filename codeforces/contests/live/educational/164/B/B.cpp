#include <bits/stdc++.h>
using namespace std;

auto get(vector<int> a) {
    queue<int> q;
    for (auto& c : a) q.push(c);
    vector<pair<int, int>> ans;
    while (!q.empty()) {
        int x = q.front();
        int cnt = 0;
        while (!q.empty() && q.front() == x) {
            cnt++;
            q.pop();
        }
        ans.push_back({ x, cnt });
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int cnt = count(a.begin(), a.end(), a[0]);
    if (cnt == n) {
        cout << -1 << endl;
        return;
    }
    if (a[0] != a[n - 1]) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        set<int> s = { a[i - 1], a[i], a[i + 1] };
        if (s.size() == 3) {
            cout << 0 << endl;
            return;
        }
    }
    bool flag = false;
    for (int i = 1; i < n - 1; i++) {
        if (flag && a[i - 1] == a[i] && a[i] != a[i + 1]) {
            cout << 0 << endl;
            return;
        }
    }
    auto g = get(a);
    int m = g.size();
    vector<int> res;
    for (int i = 0; i < m; i++) {
        if (i == 0 || i == m - 1) {
            res.push_back(g[i].second);
        }
        else {
            if (i + 2 == n || a[i] != a[i + 2])
                res.push_back(g[i + 1].second);
        }
    }
    cout << *min_element(res.begin(), res.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
