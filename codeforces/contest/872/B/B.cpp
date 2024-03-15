#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

int f(int A, int B, int C) {
    int ans = (A - B) * (n - 1) + (A - C) * (m - 1);
    ans += (n - 1) * (m - 1) * (A - B);
    return ans;
}

int g(int A, int B, int C) {
    int ans = (B - A) * (n - 1) + (C - A) * (m - 1);
    ans += (n - 1) * (m - 1) * (B - A);
    return ans;
}

void solve() {
    cin >> n >> m;
    int t = n * m;
    vector<int> a(t);
    for (auto& c : a)cin >> c;

    sort(a.begin(), a.end());
    if (n < m)swap(n, m);

    int ans = max(f(a[t - 1], a[0], a[1]), g(a[0], a[t - 1], a[t - 2]));
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}