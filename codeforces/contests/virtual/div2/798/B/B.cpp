#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    vector<int> q(n);
    for (int i = 0; i < n - 1; i++) {
        int cnt = s.count(p[i]);
        s.erase(p[i]);
        q[i] = *s.begin();
        s.erase(s.begin());
        if (cnt) s.insert(p[i]);
    }
    q[n - 1] = *s.begin();
    if (p[n - 1] == q[n - 1]) {
        swap(q[n - 2], q[n - 1]);
    }
    for (auto& c : q) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}