#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int x = accumulate(a.begin(), a.end(), 0LL);
    int y = accumulate(b.begin(), b.end(), 0LL);
    if (x > y) cout << 0;
    else if (x < y)cout << 1;
    else cout << -1;
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}