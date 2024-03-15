#include <bits/stdc++.h>
#define Mine pair<int,int>
#define F first
#define S second
using namespace std;

const int INF = 2e9;
void solve() {
    int a, n, m; cin >> a >> n >> m;
    set<int> rain;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        for (int j = x + 1; j <= y; j++) rain.insert(j);
    }
    vector<Mine> umb(m);
    for (auto& [x, w] : umb) cin >> x >> w;
    sort(umb.begin(), umb.end());
    vector<int> dp(a + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= a; i++) {
        if (rain.count(i)) {
            bool b = false;
            for (auto& [x, w] : umb) {
                if (x >= i) break;
                dp[i] = min(dp[i], dp[x] + (i - x) * w);
                b = true;
            }
            if (!b) { cout << -1 << endl; return; }
        }
        else dp[i] = dp[i - 1];
    }
    cout << dp[a] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}