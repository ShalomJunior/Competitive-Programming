#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x]++;
    }
    int M = 0;
    multiset<int> ms;
    for (auto& [k, v] : h) {
        ms.insert(v);
        M = max(M, v);
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        vector<int> del;
        for (int j = 0; ; j++) {
            auto it = ms.lower_bound(i * (1 << j));
            if (it == ms.end()) break;
            del.push_back(*it);
            ms.erase(it);
        }
        ans = max(ans, i * ((1 << del.size()) - 1));
        for (auto& c : del)ms.insert(c);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}