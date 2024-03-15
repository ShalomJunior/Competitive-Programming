#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> p, s;
    for (int i = 0; i < n; i++) {
        p.insert(i);
        s.insert(i);
    }
    int mx = *max_element(a.begin(), a.end());
    vector<int> pre(n), suf(n);
    for (int i = 0; i < n; i++) {
        p.erase(a[i]);
        pre[i] = p.empty() ? mx + 1 : *p.begin();
    }
    for (int i = n - 1; i >= 0; i--) {
        s.erase(a[i]);
        suf[i] = s.empty() ? mx + 1 : *s.begin();
    }
    for (int i = 0; i < n - 1; i++) {
        if (pre[i] == suf[i + 1]) {
            cout << 2 << endl;
            cout << 1 << " " << i + 1 << endl;
            cout << i + 2 << " " << n << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}