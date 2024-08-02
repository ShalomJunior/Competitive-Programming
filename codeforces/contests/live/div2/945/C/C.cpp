#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int i, int j) {
        return p[i] > p[j];
        });
    for (auto& c : o) cerr << c << " -> ";
    cerr << endl;
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(i + 1);
    int can = (n - 2) / 2;
    vector<int> q(n, -1);
    for (int i = 0; i < can; i++) {
        if (o[i] == 0 || o[i] == n - 1) continue;
        int j = o[i];
        vector<int> x;
        int cnt = 0;
        for (auto qs : { q[j - 1], q[j + 1] }) {
            if (qs == -1) {
                x.push_back(*s.begin());
                s.erase(s.begin());
                cnt++;
            }
        }
        if (cnt == 1) {
            if (q[j - 1] == -1) q[j - 1] = x[0];
            else q[j + 1] = x[0];
        }
        else {
            q[j - 1] = x[0];
            q[j + 1] = x[1];
            bool a = q[j - 1] < q[j + 1];
            bool b = p[j - 1] < p[j + 1];
            if (a ^ b) {
                swap(q[j - 1], q[j + 1]);
            }
        }
        int mx = max(q[j - 1], q[j + 1]);
        int mn = q[j] < mx ? mx - q[j] + 1 : 0;
        auto it = s.lower_bound(mn);
        q[j] = *it;
        s.erase(it);
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
