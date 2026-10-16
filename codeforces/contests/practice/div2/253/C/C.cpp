#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> e, o;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x & 1 ? o.push_back(x) : e.push_back(x);
    }
    int a = p;
    int b = k - p;
    int x = e.size();
    int y = o.size();
    if (y < b || (y - b) & 1 || x + (y - b) / 2 < a) {
        cout << "NO" << endl;
        return;
    }
    int j = 0;
    vector<vector<int>> ans(k);
    for (int i = 0; i < b; i++, j++) {
        ans[j].push_back(o.back());
        o.pop_back();
    }
    for (int i = 0; i < a; i++, j++) {
        if (!e.empty()) {
            ans[j].push_back(e.back());
            e.pop_back();
        }
        else {
            ans[j].push_back(o.back());
            o.pop_back();
            ans[j].push_back(o.back());
            o.pop_back();
        }
    }
    for (auto& c : e) ans[k - 1].push_back(c);
    for (auto& c : o) ans[k - 1].push_back(c);
    cout << "YES" << endl;
    for (auto& v : ans) {
        cout << v.size() << " ";
        for (auto& c : v) cout << c << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
