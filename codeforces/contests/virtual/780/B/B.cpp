#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    if (n == 1) {
        cout << (a[0] == 1 ? "YES" : "NO") << endl;
        return;
    }
    cout << (a[n - 2] + 1 < a[n - 1] ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}