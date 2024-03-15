#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = a[i] + (i ? pre[i - 1] : 0);
    }
    vector<int> x;
    for (int i = 0; i < n; i++) {
        x.push_back(pre[i]);
        for (int j = 0; j <= i; j++) {
            x.push_back(pre[i] - pre[j]);
        }
    }
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    int id, cnt = 0;
    for (auto& target : x) {
        vector<int> dp(n);
        map<int, vector<int>> h;
        for (int i = 0; i < n; i++) {
            h[pre[i]].push_back(i);
            int l = pre[i] - target;
            if (h.count(l)) {
                int j = h[l].back();
                dp[i] = max((i ? dp[i - 1] : 0), 1 + dp[j]);
            }
            else if (!i && pre[i] == target) dp[i] = 1;
            dp[i] = max(dp[i], i ? dp[i - 1] : 0);
        }
        cout << dp[n - 1] << endl;
        if (dp[n - 1] > cnt) {
            id = target;
            cnt = dp[n - 1];
        }
    }
    cout << id << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; ) {

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}