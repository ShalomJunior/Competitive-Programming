#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a)cin >> c;
    sort(a.begin(), a.end());
    if (!k) { cout << (a[0] == 1 ? -1 : 1) << endl; return; }
    if (k == n) { cout << a[n - 1] << endl; return; }
    cout << (a[k - 1] == a[k] ? -1 : a[k - 1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}