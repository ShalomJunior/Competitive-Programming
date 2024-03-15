#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    cout << (a[n - 1] <= d || a[0] + a[1] <= d ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}