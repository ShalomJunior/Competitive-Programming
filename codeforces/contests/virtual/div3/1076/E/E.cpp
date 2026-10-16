#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;
void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> dp(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        if (s.count(i)) {
            dp[i] = 1;
        }
        else {
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    int a = j;
                    int b = i / j;
                    if (s.count(a)) dp[i] = min(dp[i], dp[b] + 1);
                    if (s.count(b)) dp[i] = min(dp[i], dp[a] + 1);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << (dp[i] < INF ? dp[i] : -1) << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}