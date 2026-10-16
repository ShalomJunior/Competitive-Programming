#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 6;
const int INF = 2e9;
void solve() {
    vector<int> x(N);
    vector<int> y(N);
    int l = INF;
    int r = INF;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        l = min(l, x[i]);
        r = min(r, y[i]);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += x[i] - l;
        ans += y[i] - r;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
