#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first;
    for (int i = 0; i < n; i++) cin >> p[i].second;
    sort(p.begin(), p.end());
    vector<int> all;
    for (auto& [l, r] : p) {
        all.push_back(l - 1);
        all.push_back(l);
        all.push_back(l + 1);
        all.push_back(r - 1);
        all.push_back(r);
        all.push_back(r + 1);
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int ended = 0;
    priority_queue<int, vector<int>, greater<int>> running;
    int j = 0;
    int ans = 0;
    for (auto& price : all) {
        if ((int)running.size() <= k) {
            ans = max(ans, price * (n - ended));
        }
        while (j < n && p[j].first == price) {
            running.push(p[j].second);
            j++;
        }
        while (!running.empty() && running.top() == price) {
            ended++;
            running.pop();
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
