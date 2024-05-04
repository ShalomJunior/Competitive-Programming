#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, a;
    cin >> n >> a;
    vector<int> d(n);
    for (auto& c : d) cin >> c;
    int s = accumulate(d.begin(), d.end(), 0LL);
    for (int i = 0; i < n; i++) {
        pair<int, int> x = { n - 1, s - d[i] };
        pair<int, int> y = { a - d[i], a - 1 };
        pair<int, int> res = { max(x.first, y.first), min(x.second, y.second) };
        int can = max(res.second - res.first + 1, 0LL);
        cout << d[i] - can << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
