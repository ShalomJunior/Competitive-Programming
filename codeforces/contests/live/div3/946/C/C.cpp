#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    map<pair<int, int>, map<int, int>> cnt1, cnt2, cnt3;
    map<pair<int, int>, int> tot1, tot2, tot3;
    int ans = 0;
    for (int i = 2; i < n; i++) {
        int x = a[i - 2];
        int y = a[i - 1];
        int z = a[i];
        ans += tot1[{y, z}] - cnt1[{y, z}][x];
        ans += tot2[{x, z}] - cnt2[{x, z}][y];
        ans += tot3[{x, y}] - cnt3[{x, y}][z];
        cnt1[{y, z}][x]++;
        tot1[{y, z}]++;
        cnt2[{x, z}][y]++;
        tot2[{x, z}]++;
        cnt3[{x, y}][z]++;
        tot3[{x, y}]++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
