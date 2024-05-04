#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        bool b = false;
        for (auto &[L, R]: a) b |= (L <= i && i <= R);
        if (!b) ans.push_back(i);
    }   
    int z = ans.size();
    cout << z << endl;
    if (z) { 
        for (auto &c: ans)cout << c << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}