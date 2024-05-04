#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int mem = 0;
    vector<int> vec(n);
    for (auto& c : vec) {
        cin >> c; mem += c;
    }
    vector<int> a;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x & 1) a.push_back(vec[i]);
        else pq.push(vec[i]);
    }
    if (mem < m) { cout << -1 << endl; return; }
    sort(a.begin(), a.end());
    int ans = 0;
    while (m > 0) {
        if (!a.empty()) {
            if (a.back() >= m || !pq.empty() && pq.top() <= a.back()) {
                m -= a.back();
                a.pop_back();
                ans++;
                continue;
            }
            int z = a.size();
            int mx = pq.empty() ? 0 : pq.top();
            if (z > 1 && a[z - 2] + a[z - 1] > ) {

            }
        }
        else {
            m -= pq.top();
            pq.pop();
            ans += 2;
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}