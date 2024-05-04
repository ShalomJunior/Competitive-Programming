#include <bits/stdc++.h>
#define int long long
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

void solve() {
    int n, m, h; cin >> n >> m >> h;
    vector<vector<int>> a(n, vector<int>(m));
    vector<Mine> rank(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
            if (sum > h) break;
            rank[i].F++;
            rank[i].S += sum;
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (rank[i].F > rank[0].F ||
            (rank[i].F == rank[0].F && rank[i].S < rank[0].S)) ans++;
    }
    cout << ans + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}