#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> q(n - 1), g(n - 1);
    for (int i = 0, sum = 0; i < n - 1; i++) {
        cin >> q[i];
        g[i] = (sum += q[i]);
    }
    int M = *max_element(g.begin(), g.end());
    int m = *min_element(g.begin(), g.end());
    if (!M || M >= n || m <= -n || set<int>(g.begin(), g.end()).size() != n - 1) {
        cout << -1 << endl;
        return;
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    vector<int> p(n);
    p[0] = n - (M < 0 ? 0 : M); s.erase(p[0]);
    for (int i = 0; i < n - 1; i++) {
        int need = p[i] + q[i];
        if (!s.count(need)) {
            cout << -1 << endl;
            return;
        }
        p[i + 1] = need;
        s.erase(need);
    }
    for (auto& c : p) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}