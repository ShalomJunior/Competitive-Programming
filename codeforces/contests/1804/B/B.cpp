#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, d, w;
    cin >> n >> k >> d >> w;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        q.push(v);
    }

    int ans = 0;
    while (!q.empty()) {
        int start = q.front() + w;
        int cnt = 0;
        ans++;
        while (q.front() <= start + d && cnt < k && !q.empty()) {
            q.pop();
            cnt++;
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}