#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int>> a(n);
    vector<int> all;
    for (auto& [l, r] : a) {
        cin >> l >> r;
        all.push_back(l);
        all.push_back(r);
    }
    sort(a.begin(), a.end());
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    int ans = 0;
    priority_queue<int> ended;
    priority_queue<int, vector<int>, greater<int>> running;
    int i = 0;
    for (auto& c : all) {
        while (i < n && a[i].first == c) {
            if (ended.empty() || y * (a[i].first - ended.top()) > x) {
                ans += x;
                ended.push(c);
            }
            int r = ended.top();
            ended.pop();
            ans += y * (a[i].second - r) % MOD;
            running.push(a[i].second);
            i++;
        }
        while (!running.empty() && running.top() == c) {
            ended.push(running.top());
            running.pop();
        }
        ans %= MOD;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}