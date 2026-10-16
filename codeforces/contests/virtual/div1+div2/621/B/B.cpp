#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> s(a.begin(), a.end());
    int mx = *prev(s.end());
    cout << (s.count(x) ? 1 : max(2, (x + mx - 1) / mx)) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}