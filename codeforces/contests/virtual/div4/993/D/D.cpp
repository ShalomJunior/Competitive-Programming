#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n, -1);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (s.count(a[i])) continue;
        else {
            b[i] = a[i];
            s.insert(b[i]);
        }
    }
    set<int> r;
    for (int i = 1; i <= n; i++) {
        if (!s.count(i)) r.insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            b[i] = *r.begin();
            r.erase(r.begin());
        }
    }
    for (auto& c : b) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}