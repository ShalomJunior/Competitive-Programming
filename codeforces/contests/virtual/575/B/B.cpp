#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        q.push(x);
    }
    vector<int> ans;
    while (ans.size() != k) {
        int sum = 0, cnt = 0;
        while (!q.empty() && sum % 2 == 0) {
            sum += q.front();
            cnt++;
            q.pop();
        }
        if (sum & 1) ans.push_back(cnt + (ans.empty() ? 0 : ans.back()));
        if (q.empty() && ans.size() != k) {
            cout << "NO" << endl;
            return;
        }
        if (ans.size() == k) {
            while (!q.empty()) {
                sum += q.front();
                q.pop();
            }
            if (sum & 1) {
                ans.pop_back();
                ans.push_back(n);
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (auto& c : ans) cout << c << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}