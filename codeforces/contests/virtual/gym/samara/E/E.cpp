#include <bits/stdc++.h>
using namespace std;

struct info {
    int a;
    int b;
    int id;
    bool operator<(const info& o) const {
        if (b != o.b) return b < o.b;
        return a < o.a;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<info> p(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p[i] = { a, b, i + 1 };
    }
    sort(p.begin(), p.end());
    set<pair<int, int>> s;
    vector<int> ans;
    int i = m;
    while (i > 0) {
        while (!p.empty() && p.back().b >= i) {
            s.insert({ p.back().a, p.back().id });
            p.pop_back();
        }
        if (s.empty()) {
            cout << "NO" << endl;
            return;
        }
        auto [a, id] = *s.begin();
        if (a > i) {
            cout << "NO" << endl;
            return;
        }
        ans.push_back(id);
        i = a - 1;
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}