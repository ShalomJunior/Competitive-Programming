#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    reverse(a.begin(), a.end());
    bool ans = true;
    for (int i = 0; i < n; i++) {
        int cnt = a.end() - upper_bound(a.begin(), a.end(), i);
        ans &= (a[n - 1 - i] == cnt);
    }
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}