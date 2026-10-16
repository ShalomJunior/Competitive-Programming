#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int f = n % m;
    int g = m - f;
    cout << min(f * b, g * a) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
