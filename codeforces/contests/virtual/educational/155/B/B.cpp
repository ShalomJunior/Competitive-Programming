#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int ma = *min_element(a.begin(), a.end());
    int mb = *min_element(b.begin(), b.end());
    int sa = accumulate(a.begin(), a.end(), 0LL);
    int sb = accumulate(b.begin(), b.end(), 0LL);
    cout << min(n * ma + sb, n * mb + sa) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
