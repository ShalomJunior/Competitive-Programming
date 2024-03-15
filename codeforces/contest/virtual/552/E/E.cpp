#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({ a[i], i });
    }
    vector<int> ans(n);
    set<int> pos;
    for (int i = 0; i < n; i++) {
        pos.insert(i);
    }
    int id = 1;
    while (!s.empty()) {
        auto p = *prev(s.end());
        int cnt = k;
        vector<int> to_del;
        for (auto it = pos.upper_bound(p.second); it != pos.end() && cnt; it++, cnt--) {
            ans[*it] = id;
            to_del.push_back(*it);
        }
        cnt = k + 1;
        for (auto it = pos.lower_bound(p.second); cnt; it--, cnt--) {
            ans[*it] = id;
            to_del.push_back(*it);
            if (it == pos.begin()) break;
        }
        if (cnt) {
            ans[*pos.begin()] = id;
            to_del.push_back(*pos.begin());
        }
        for (auto& i : to_del) {
            pos.erase(i);
            s.erase({ a[i], i });
        }
        id++;
        if (id == 3) id = 1;
    }
    for (auto& c : ans) cout << c;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}