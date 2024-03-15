#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int sum = 0;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        sum += a;
        vec[i].F = a;
        vec[i].S = a - b;
    }
    if (sum <= m) { cout << 0 << endl; return; }
    sort(vec.begin(), vec.end(), [&](Mine& a, Mine& b) {
        return a.S > b.S;
        });
    for (int i = 0; i < n; i++) {
        sum -= vec[i].S;
        if (sum <= m) { cout << i + 1 << endl; return; }
    }
    cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}