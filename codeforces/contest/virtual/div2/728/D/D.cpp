#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
using T = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<T> v(n);
    for (auto& [x, y] : v) cin >> x >> y;
    sort(v.begin(), v.end(), [&](const T& a, const T& b) {
        return a.S > b.S;
        });
    int i = 0, j = n - 1;
    long long ans = 0, sum = 0;
    while (i <= j) {
        int d = min(v[i].F, max(v[j].S - sum, 0LL));
        sum += d;
        v[i].F -= d;
        ans += d * 2;
        if (sum >= v[j].S) {
            ans += v[j].F;
            sum += v[j].F;
            j--;
        }
        if (v[i].F == 0) i++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}