#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int m = max(*min_element(a.begin(), a.end()), 2);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int x = a[i] - a[i] % m;
        ans[i] = (a[i] - x < x + m - a[i] ? x : x + m);
    }
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}