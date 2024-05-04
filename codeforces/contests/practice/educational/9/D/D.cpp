#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), cnt(N + 1);
    for (auto& c : a) {
        cin >> c;
        if (c <= N) cnt[c]++;
    }
    vector<int> dp(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            dp[j] += cnt[i];
        }
    }
    int lcm = max_element(dp.begin(), dp.end()) - dp.begin();
    if (dp[lcm] == 0) {
        cout << 1 << " " << 0 << endl;
        return;
    }
    cout << lcm << " " << dp[lcm] << endl;
    for (int i = 0; i < n; i++) {
        if (lcm % a[i] == 0) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
