#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, vector<int>> f;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f[x].push_back(i);
    }
    map<int, vector<int>> group;
    for (auto& [k, vec] : f) {
        int z = vec.size();
        int inter = 0;
        for (int i = 0; i < z; i++) {
            if (!i) inter = vec[i] + 1;
            if (i) inter = max(inter, vec[i] - vec[i - 1]);
            if (i == z - 1) inter = max(inter, n - vec[i]);
        }
        group[inter].push_back(k);
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
        for (auto& c : group[i])s.insert(c);
        cout << ((s.empty() ? -1 : *s.begin())) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}