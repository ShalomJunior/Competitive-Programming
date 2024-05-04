#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> s;
    for (int i = 0; i <= n; i++)s.insert(i);
    for (int i = 0; i < n; i++) {
        int x = *s.begin();
        int y = *next(s.begin());
        int val = -(a[i] - y);
        if (val == x) {
            cout << val << " ";
            s.erase(val);
            continue;
        }
        val = -(a[i] - x);
        if (s.count(val)) {
            cout << val << " ";
            s.erase(val);
            continue;
        }
        assert(false);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}