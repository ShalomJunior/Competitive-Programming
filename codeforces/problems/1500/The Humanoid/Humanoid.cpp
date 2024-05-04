#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(vector<int>& v, int i, int h, int g, int b) {
    if (i == (int)v.size())return 0;

    if (v[i] < h) return f(v, i + 1, h + v[i] / 2, g, b) + 1;

    int ans1 = (g) ? f(v, i, h * 2, g - 1, b) : 0;
    int ans2 = (b) ? f(v, i, h * 3, g, b - 1) : 0;
    return max(ans1, ans2);
}

void solve() {
    int n, h; cin >> n >> h;
    vector<int> v(n);
    for (auto& c : v)cin >> c;
    sort(v.begin(), v.end());
    cout << f(v, 0, h, 2, 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}