#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int M = *max_element(a.begin(), a.end());
    int ans = 0;
    set<int> s(a.begin(), a.end());
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == M) break;
        if (!s.count(a[i])) continue;
        ans++;
        vector<int> del;
        for (auto it = s.lower_bound(a[i]); ; it--) {
            del.push_back(*it);
            if (it == s.begin()) break;
        }
        for (auto& c : del) s.erase(c);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}