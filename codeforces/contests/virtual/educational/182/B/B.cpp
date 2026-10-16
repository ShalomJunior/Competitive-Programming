#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    vector<int> a(n);
    for (auto& c : a) {
        cin >> c;
        s.erase(c);
    }
    if (s.size() == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                a[i] = *s.begin();
            }
        }
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int l = 0;
    while (l < n && a[l] == p[l]) l++;
    int r = n - 1;
    while (r >= 0 && a[r] == p[r]) r--;
    if (l <= r) {
        cout << n - l - (n - 1 - r);
    }
    else {
        cout << 0;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}