#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, r; cin >> n >> r;
    int id = 0;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        if (b) {
            ++id;
            for (int j = 0; j < r; j++) {
                if (i - j >= 0) a[i - j].push_back(id);
                if (i + j < n) a[i + j].push_back(id);
            }
        }
    }
    set<int> ans;
    for (int i = 0; i < n; i++) {
        int m = a[i].size();
        if (!m) { cout << -1 << endl; return; }
        bool done = false;
        for (auto& c : a[i]) {
            if (ans.count(c)) {
                done = true;
                break;
            }
        }
        if (!done) ans.insert(a[i].back());
    }
    cout << ans.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}