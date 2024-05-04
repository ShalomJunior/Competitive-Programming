#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> last(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[last[a[i]]] + 1;
        last[a[i]] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
